function [] = montecarlo_function( num_targets, num_obstacles, courses, VERIFICATION )

    % PARAMETERS to guide creation:
    min_dist_ot = 0;%    - min distance between targets and obstacles:  min_dist_ot
    min_dist_t = 0; %    - min distance between different targets:      min_dist_t
    min_dist_o = 0;%    - min distance between different obstacles:    min_dist_o
    max_dist_ot = -1;%5;%    - obstacles: max distance from a target        max_dist_ot
    % Number of targets and obstacles:
    max_targets = num_targets;
    max_obstacles = num_obstacles;
    min_targets = num_targets;
    min_obstacles = num_obstacles;

    % MONTE CARLO
    % -------------------------------------------
    rng(0,'twister'); % initialise random number generator with a seed

    COURSES = courses; % NUMBER OF COURSES TO CREATE
    for i=1:COURSES
        % Setup a filename for the scenario
        if VERIFICATION~=1
            filename = 'MontecarloScenarios/Input/scenario';
            scen_num = int2str(i);
            filename = strcat(filename,scen_num);
            filename = strcat(filename,'.csv');
        else % if VERIFICATION==1
            % Setup a filename for the scenario
            filename = 'Verification/PathPlanningTest/Input/scenario_';
            filename = strcat(filename,int2str(num_targets));
            filename = strcat(filename,'_');
            filename = strcat(filename,int2str(num_obstacles));
            filename = strcat(filename,'_');
            scen_num = int2str(i);
            filename = strcat(filename,scen_num);
            filename = strcat(filename,'.csv');
        end
        % If a file with the name already exists, delete it (otherwise append
        % will keep appending to the end of it!)
        if exist(char(filename),'file')
            delete(filename);
        end
    
        % Generate an obstacle course
        generate_obstacle_course(filename,min_targets,max_targets,min_obstacles,max_obstacles,max_dist_ot);
    end
end


% -------------------------------------------
% Helper functions
%-------------------------------------------

% Function for generating an obstacle course
function [] = generate_obstacle_course(filename,min_targets,max_targets,min_obstacles,max_obstacles,max_dist_ot)
    targets = randi([min_targets,max_targets]);
    obstacles = randi([min_obstacles,max_obstacles]);
    grid = zeros(50,50); % grid with cells corresponding to grid lines
    % that is, the grid positions are indexed based on their lower left
    % position - so 0,0 is the cell with x,y values in [0,1)
    % Using this notation, the target/obstacle boundary consists of the 
    % 4 cells (x-1,y-1),(x-1,y),(x,y-1),(x,y)
    
    if max_dist_ot == -1 % if obstacles can be freely placed
        % Pick target positions
        for i=1:targets
            grid = pick_position(grid,'t');
        end
    
        % Pick obstacle positions
        for i=1:obstacles
            grid = pick_position(grid,'o');
        end
    else % if obstacles have to be a certain distance from targets
        % Pick target positions
        for i=1:targets
            [grid, t_list] = pick_position_trg(grid,[]);
        end
        % Pick obstacle positions
        for i=1:obstacles
            grid = pick_position_obs(grid,t_list,max_dist_ot);
        end
    end
    % Convert grid into a text file of (x,y) positions
    grid_to_file(grid,filename);
end



% Function to convert a grid into a text file
function [] = grid_to_file(grid_in,filename)
    for i=1:50
        for j = 1:50
            if abs(grid_in(i,j)) == 1
                line = [j i grid_in(i,j)];
                dlmwrite(filename,line,'delimiter',',','-append');
            end             
        end
    end
end


% Function to pick a position for an object (target/obstacle)
function grid_out = pick_position(grid_in,type_in)
    if type_in == 't'
        type_num = 1;
    else
        type_num = -1;
    end

    x = randi([3,47]);
    y = randi([3,47]);
    
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
    else % Recursive call if not clear on first go
        grid_out = pick_position(grid_in,type_in);
    end
end


% Function to pick a position for a target
function [grid_out,t_list] = pick_position_trg(grid_in,t_list_in)
    type_num = 1;
        
    x = randi([3,47]);
    y = randi([3,47]);
    
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        t_list = t_list_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
        t_list(1,end+1) = x;
        t_list(2,end+1) = y;
    else % Recursive call if not clear on first go
        [grid_out,t_list] = pick_position_trg(grid_in,t_list_in);
    end
end



% Function to pick a position for an obstacle
function grid_out = pick_position_obs(grid_in,t_list,max_dist_ot)
    type_num = -1;
    x_list = [];
    y_list = [];
    x = 0;
    y = 0;
        
    % Use the t_list of x and y values to
    for i = 1:size(t_list,2)
        x_curr = t_list(1,i);
        y_curr = t_list(2,i);
        lst = linspace(x_curr-max_dist_ot, x_curr+max_dist_ot,2*max_dist_ot+1);
        x_list = cat(2,x_list,lst);

        lst = linspace(y_curr-max_dist_ot, y_curr+max_dist_ot,2*max_dist_ot+1);
        y_list = cat(2,y_list,lst);
    end
    x_list = process_list(x_list);
    y_list = process_list(y_list);
    
    x = datasample(x_list,1);
    y = datasample(y_list,1);
        
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
    else % Recursive call if not clear on first go
        grid_out = pick_position_obs(grid_in,t_list,max_dist_ot);
    end
end

% Function to cut out indices that are not needed
function list_out = process_list(list_in)
    list_out = unique(sort(list_in));
    new_start = find(list_out==3);
    new_end   = find(list_out==47);

    if isempty(new_start)
        new_start = 0;
    end

    if isempty(new_end)
        new_end = length(list_out);
    end
    list_out = list_out(new_start:new_end);
end



% Function to check if an area is clear
function isclear = area_clear(grid_in,x_in,y_in)
    for j = (y_in-1):(y_in)
       for i = (x_in-1):(x_in)
          if grid_in(i,j) ~= 0
              isclear = false;
              return
          end
       end
    end
    isclear = true;
end

