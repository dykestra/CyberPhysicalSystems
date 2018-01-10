function [] = simSetup(obstacles, targets, hardware)
%SIMSETUP This file should setup the workspace for the simulation
%
% The execution of this file is timed and included in your course score.
% This file takes as inputs the arrays locating the obstacles and the
% targets of the obstacle course. Then your team can do any processing in
% here that you would like (such as initial path planning, etc).
%
% This function will know if the simulation is being done on the hardware
% or in software based upon the status of the "hardware" variable. If
% hardware=1, then the actual crane hardware is being used.


%% SETUP CODE
setup;

%% PATH PLANNING
MAP = info2Map(obstacles, targets);
[waypoints] = path_planning(MAP);

%% Define PIDs parameters for model
PC1x = 4.7;
IC1x = 0.9;
DC1x = 0.1;

PC1y = PC1x;
IC1y = IC1x;
DC1y = DC1x;

AnglePX = 2.0;
AngleIX = 0;
AngleDX = 0;

AnglePY = AnglePX;
AngleIY = AngleIX;
AngleDY = AngleDX;



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% DO NOT DELETE THIS
save('workspace.mat');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end
