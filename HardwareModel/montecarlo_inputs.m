% ===================================================================
% Monte Carlo generation of input files ("mazes") in .txt format
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

% PARAMETERS to guide creation:
%    - min distance between targets and obstacles:  min_dist_ot
%      - DEFAULT: 0
min_dist_ot = 0;
%    - min distance between different targets:      min_dist_t
%      - DEFAULT: 0
min_dist_t = 0;
%    - min distance between different obstacles:    min_dist_o
%      - DEFAULT: 0
min_dist_o = 0;
%    - obstacles: max distance from a target        max_dist_ot
%      - setting to -1 allows obstacles to be placed freely
max_dist_ot = 5;
% Number of targets and obstacles:
max_targets = 3;
max_obstacles = 3;
min_targets = 1;
min_obstacles = 1;

% MONTE CARLO
% -------------------------------------------
rng(0,'twister'); % initialise random number generator with a seed

COURSES = 10; % NUMBER OF COURSES TO CREATE
for i=1:COURSES
    % Setup a filename for the scenario
    filename = 'MontecarloScenarios/Input/scenario';
    scen_num = int2str(i);
    filename = strcat(filename,scen_num);
    filename = strcat(filename,'.csv');
    % If a file with the name already exists, delete it (otherwise append
    % will keep appending to the end of it!)
    if exist(char(filename),'file')
       delete(filename);
    end
    
    % Generate an obstacle course
    generate_obstacle_course(filename,min_targets,max_targets,min_obstacles,max_obstacles,max_dist_ot);
end