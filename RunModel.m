function RunModel(InputFile,OutputPath, Model)
% Suppress warnings relating to inputs and outputs not connected
warning('off','Simulink:Engine:InputNotConnected');
warning('off','Simulink:Engine:OutputNotConnected');

%% Load Variables and perform Path Planning
run('setup.m');
MAP = txt2Map(InputFile);
[targets,waypoints] = path_planning(MAP);

%% Define PIDs parameters for model
PTraj = 3.0;
ITraj = 0.3;
DTraj = 0.3;

POsc = 0.9;
IOsc = 0;
DOsc = 0.01;

%% Run Model
options = simset('SrcWorkspace','current');
sim(Model,[],options)
PostSimAnalysis(OutputPath, MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, xRange, yRange, DesiredX, DesiredY);

%% Save all information as csv and print figures
csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);

% Switch warnings relating to inputs and outputs not connected back on
warning('on','Simulink:Engine:InputNotConnected');
warning('on','Simulink:Engine:OutputNotConnected');
