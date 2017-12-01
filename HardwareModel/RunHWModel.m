% Suppress warnings relating to inputs and outputs not connected
warning('off','Simulink:Engine:InputNotConnected');
warning('off','Simulink:Engine:OutputNotConnected');

close all
clear all

InputFile = 'MontecarloScenarios/Input/scenario4.csv';
OutputPath = 'SingleScenarios/Output';

%% Function done by other group required for scoring
[obstacles_csv, targets_csv] = getCourseFromCSV(InputFile);

%% Load Variables and perform Path Planning
tic;
run('setup.m');
MAP = txt2Map(InputFile);
[waypoints] = path_planning(MAP);
ElapsedTime = toc

%% Define PIDs parameters for model
PC1x = 2.0;
IC1x = 0.1;
DC1x = 0.3;

PC2x = 3.5;
IC2x = 0.3;
DC2x = 0.3;

PC1y = 2.0;
IC1y = 0.1;
DC1y = 0.3;

PC2y = 3.5;
IC2y = 0.3;
DC2y = 0.3;

%% Run Model
Crane3D_DevDriv;
set_param('Crane3D_DevDriv','StopTime','120');
set_param('Crane3D_DevDriv/Constant','Value','waypoints');
set_param('Crane3D_DevDriv','SimulationCommand','update');
set_param('Crane3D_DevDriv','SimulationCommand','WriteDataLogs');
set_param('Crane3D_DevDriv','SimulationCommand','start');

pause(130)

%% Score run & Post simulation analysis
simout.Time = xpos.time;
simout.CartX = [xpos.time xpos.signals.values];
simout.CartY = [ypos.time ypos.signals.values];
simout.TrajX = [XTraj.time XTraj.signals.values];
simout.TrajY = [YTraj.time YTraj.signals.values];
simout.AngleX = [anglex.time anglex.signals.values];
simout.AngleY = [angley.time angley.signals.values];
simout.DesX = [XDes.time XDes.signals.values];
simout.DesY = [XDes.time YDes.signals.values];
score = getScore(simout, obstacles_csv, targets_csv, ElapsedTime)

pause(.25)

% TrajX = simout.get('TrajX');
% TrajY = simout.get('TrajY');
% CartX = simout.get('CartX');
% CartY = simout.get('CartY');
% CartdX = simout.get('CartdX');
% CartdY = simout.get('CartdY');
% AngleX = simout.get('AngleX');
% AngleY = simout.get('AngleY');
% AngledX = simout.get('AngledX');
% AngledY = simout.get('AngledY');
% 
PostSimAnalysis(OutputPath, MAP, waypoints, simout.TrajX, simout.TrajY, simout.CartX, simout.CartY, simout.AngleX, simout.AngleY, simout.DesX, simout.DesY);
% 
% %% Save all information as csv and print figures
% csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);
% 
% % Switch warnings relating to inputs and outputs not connected back on
% warning('on','Simulink:Engine:InputNotConnected');
% warning('on','Simulink:Engine:OutputNotConnected');
