% ===================================================================
% Movement verification -- creating simulation tables
% ===================================================================

% SCRIPT VERSION for 2016b onward
% Setup a file path for the scenario files
%filepath = 'Verification/Input/scenario';
    
% Generate movement tests
%create_movement_tests(filepath);


% -------------------------------------------
% Function to create the "Queen movement" pattern
% -------------------------------------------
%function [] = create_movement_tests(filepath) %2016b onward
function [] = movement_verification(filepath)
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
    if exist(filename, 'file') ~= 2
        % Write the starting point to the file
        line = [start_x start_y 1];
        dlmwrite(filename,line,'delimiter',',','-append');
        
        % Write the ending point to the file
        line = [end_x end_y 1];
        dlmwrite(filename,line,'delimiter',',','-append');
    end
end