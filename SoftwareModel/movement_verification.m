% ===================================================================
% Movement verification
% ===================================================================

% ASSUMPTIONS:
% Cohort agreement:
% - coordinates: x, y are integers, with x, y \in [3, 47]
% - target/obstacle size: targets and obstacles are 2cmx2cm boxes
%   centred at the point given by the x and y coordinates
%   -> top left corner: x-1,y+1
%      bottom right:    x+1,y-1
% - distance between obstacles and targets: obstacle and target 
%   boxes (2cm x 2cm) shall not overlap
% - number of targets: 1 =< targets =< 3
% - number of obstacles: 1 =< obstacles =< 3

% Due to Matlab's arrays starting with index 1, the temporary grid 
% generated below uses a convention where the grid positions are "as if" on
% the cells (instad of the gridlines as they are in reality), indexed based 
% on their lower left grid position - so 0,0 is the cell with x,y values in 
% [0,1).
% Using this notation, the target/obstacle boundary consists of the 4 cells 
% (x-1,y-1),(x-1,y),(x,y-1),(x,y)
% Note that, although Matlab's arrays starting with index 1, and we could 
% therefore not represent points with either x or y index 0, this is not
% an issue here as these regions are outside the allowed area.



% Setup a file path for the scenario files
filepath = 'Verification/Input/scenario';


% Generate an obstacle course
%generate_obstacle_course(filename,min_targets,max_targets,min_obstacles,max_obstacles);
    
% Generate movement tests
create_movement_tests(filepath);


% -------------------------------------------
% Function to create the "Queen movement" pattern
% -------------------------------------------
function [] = create_movement_tests(filepath)
    START_x = 3;
    START_y = 3;
    
    if START_x < 3
        positions_x = 3:47;
    else
        positions_x = START_x+1:47;
    end
    if START_y < 3
        positions_y = 3:47;
    else
        positions_y = START_y+1:47;
    end

    % horizontal
    for x=positions_x
        % Setup a filename for the scenario
        scen_num = strcat(strcat(int2str(x),'_'),int2str(positions_y(1)));
        file_to = strcat(strcat(filepath,'_to_'),scen_num);
        file_frm = strcat(strcat(filepath,'_frm_'),scen_num);
        %filename = strcat(filename,'.csv');

        test_course(strcat(file_to,'.csv'),START_x,START_y,x,positions_y(1));
        test_course(strcat(file_frm,'.csv'),x,positions_y(1),START_x,START_y); 
    end
    
    % vertical
    for y=positions_y
        % Setup a filename for the scenario
        scen_num = strcat(strcat(int2str(positions_x(1)),'_'),int2str(y));
        file_to = strcat(strcat(filepath,'_to_'),scen_num);
        file_frm = strcat(strcat(filepath,'_frm_'),scen_num);
        %filename = strcat(filename,'.csv');
     
        test_course(strcat(file_to,'.csv'),START_x,START_y,positions_x(1),y);
        test_course(strcat(file_frm,'.csv'),positions_x(1),y,START_x,START_y); 
    end
    
    % diagonal
    for x=positions_x
        for y=positions_y
            if (x == y)
                % Setup a filename for the scenario
                scen_num = strcat(strcat(int2str(x),'_'),int2str(y));
                file_to = strcat(strcat(filepath,'_to_'),scen_num);
                file_frm = strcat(strcat(filepath,'_frm_'),scen_num);
                %filename = strcat(filepath,scen_num);
                %filename = strcat(filename,'.csv');

                test_course(strcat(file_to,'.csv'),START_x,START_y,x,y);
                test_course(strcat(file_frm,'.csv'),x,y,START_x,START_y);
            end
        end
    end
end



% -------------------------------------------
% Function to create a given test course
% -------------------------------------------
function [] = test_course(filename,start_x,start_y,end_x,end_y)
    
    % Write the starting point to the file
    line = [start_x start_y 1];
    dlmwrite(filename,line,'delimiter',',','-append');

    % Write the ending point to the file
    line = [end_x end_y 1];
    dlmwrite(filename,line,'delimiter',',','-append');
end