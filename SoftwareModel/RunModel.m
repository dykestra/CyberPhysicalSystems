function RunModel(InputFile,OutputPath, Model)
%% Suppress warnings relating to inputs and outputs not connected
warning('off','Simulink:Engine:InputNotConnected');
warning('off','Simulink:Engine:OutputNotConnected');

%% Function done by other group required for scoring
[obstacles_csv, targets_csv] = getCourseFromCSV(InputFile);

%% Load Variables and perform Path Planning
tic;

run('setup.m');
MAP = txt2Map(InputFile);
[waypoints] = path_planning(MAP);

ElapsedTimePP = toc

%% Define PIDs parameters for model
PTraj = 3.0;
ITraj = 0.3;
DTraj = 0.3;

POsc = 0.9;
IOsc = 0;
DOsc = 0.01;

% PARAMETERS ADDED FROM PREV CONTROLLER WITH HW MODEL
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


%LATEST 2Controller version
PC1x = 4.7;
IC1x = 0.9;
DC1x = 0.1;

% PC2x = 3.0;
% IC2x = 0.1;
% DC2x = 0.3;
% 
% PC3x = 3.5;
% IC3x = 0.2;
% DC3x = 0.4;
% 
% PC4x = 3.7;
% IC4x = 0.3;
% DC4x = 0.5;
% 
PC1y = PC1x;
IC1y = IC1x;
DC1y = DC1x;
% 
% PC2y = PC2x;
% IC2y = IC2x;
% DC2y = DC2x;
% 
% PC3y = PC3x;
% IC3y = IC3x;
% DC3y = DC3x;
% 
% PC4y = PC4x;
% IC4y = IC4x;
% DC4y = DC4x;

AnglePX = 2.0;
AngleIX = 0;
AngleDX = 0;

AnglePY = AnglePX;
AngleIY = AngleIX;
AngleDY = AngleDX;


%% Run Model
options = simset('SrcWorkspace','current','ReturnWorkspaceOutputs','on');
simout = sim(Model,[],options);

%% Score run & Post simulation analysis
TrajX = simout.get('TrajX');
TrajY = simout.get('TrajY');
CartX = simout.get('CartX');
CartY = simout.get('CartY');
CartdX = simout.get('CartdX');
CartdY = simout.get('CartdY');
AngleX = simout.get('AngleX');
AngleY = simout.get('AngleY');
AngledX = simout.get('AngledX');
AngledY = simout.get('AngledY');

simout_b.Time = TrajX(:,1);
simout_b.CartX = CartX;
simout_b.CartY = CartY;
simout_b.TrajX = TrajX;
simout_b.TrajY = TrajY;
simout_b.AngleX = AngleX;
simout_b.AngleY = AngleY;
simout_b.DesX = simout.get('DesiredX');
simout_b.DesY = simout.get('DesiredY');

score = getScore(simout_b, obstacles_csv, targets_csv, ElapsedTimePP)

PostSimAnalysis(OutputPath, MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, simout.get('xRange'), simout.get('yRange'), simout.get('DesiredX'), simout.get('DesiredY'));

%% Save all information as csv and print figures
%csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);
output_data = strcat(OutputPath,'/Results.csv');
csvwrite(char(output_data), [simout_b.TrajX, simout_b.TrajY(:,2), simout_b.CartX(:,2), simout_b.CartY(:,2), simout_b.AngleX(:,2), simout_b.AngleY(:,2), simout_b.DesX(:,2), simout_b.DesY(:,2)]);

% Switch warnings relating to inputs and outputs not connected back on
warning('on','Simulink:Engine:InputNotConnected');
warning('on','Simulink:Engine:OutputNotConnected');
