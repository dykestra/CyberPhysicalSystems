% Suppress warnings relating to inputs and outputs not connected
warning('off','Simulink:Engine:InputNotConnected');
warning('off','Simulink:Engine:OutputNotConnected');

InputFile = 'SingleScenarios/Input/scenario1.csv';
OutputFile = 'SingleScenarios/Output';

%% Function done by other group required for scoring
[obstacles_csv, targets_csv] = getCourseFromCSV(InputFile);

%% Load Variables and perform Path Planning
tic;

run('setup.m');
MAP = txt2Map(InputFile);
[targets,waypoints] = path_planning(MAP);

ElapsedTimePP = toc;

%% Define PIDs parameters for model
P = 3.0;
I = 0.3;
D = 0.3;

POsc = 0.9;
IOsc = 0;
DOsc = 0.01;

%% Run Model
Crane3D_DevDriv;
set_param('Crane3D_DevDriv','StopTime','120');
set_param('Crane3D_DevDriv/Constant','Value','waypoints');
% set_param('Crane3D_DevDriv/Controller/PID Controler/PID Controller','P','PTraj','I','ITraj','D','DTraj');
% set_param('Crane3D_DevDriv/Controller/PID Controler/PID Controller2','P','PTraj','I','ITraj','D','DTraj');
% set_param('Crane3D_DevDriv/Controller/xRange','VariableName','XRange');
% set_param('Crane3D_DevDriv/Controller/yRange','VariableName','YRange');
% set_param('Crane3D_DevDriv','SimulationCommand','update');
% set_param('Crane3D_DevDriv','SimulationCommand','WriteDataLogs');
set_param('Crane3D_DevDriv','SimulationCommand','start');

%% Score run & Post simulation analysis
% score = getScore(simout, obstacles_csv, targets_csv)
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
% PostSimAnalysis(OutputPath, MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, simout.get('xRange'), simout.get('yRange'), simout.get('DesiredX'), simout.get('DesiredY'));
% 
% %% Save all information as csv and print figures
% csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);
% 
% % Switch warnings relating to inputs and outputs not connected back on
% warning('on','Simulink:Engine:InputNotConnected');
% warning('on','Simulink:Engine:OutputNotConnected');
