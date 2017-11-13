%% Load Variables and perform Path Planning
run('setup.m');
load('5050Grid.mat')
[targets,waypoints] = path_planning(MAP);

%% Define PIDs parameters for model
PTraj = 2.0;
ITraj = 0.3;
DTraj = 0.1;

POsc = 0.9;
IOsc = 0;
DOsc = 0.01;

%% Run Model
options = simset('SrcWorkspace','current');
sim('Simscape_crane_software_model_RealSensors_R2016b',[],options)
PostSimAnalysis(MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, xRange, yRange);

%% Save all information as csv and print figures
csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);