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