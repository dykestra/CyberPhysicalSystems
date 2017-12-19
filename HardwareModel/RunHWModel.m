% Suppress warnings relating to inputs and outputs not connected
warning('off','Simulink:Engine:InputNotConnected');
warning('off','Simulink:Engine:OutputNotConnected');

close all
clear all

InputFile = 'MontecarloScenarios/Input/scenario1.csv';
%OutputPath = 'SingleScenarios/Output';
filename = dir('MontecarloScenarios/Input/scenario1.csv');
scen_name = strsplit(filename.name,'.');
OutputPath = strcat('MontecarloScenarios/Output/2/',scen_name(1));

%% Function done by other group required for scoring
[obstacles_csv, targets_csv] = getCourseFromCSV(InputFile);

%% Load Variables and perform Path Planning
tic;
setup;
%run('setup.m');
MAP = txt2Map(InputFile);
[waypoints] = path_planning(MAP);
ElapsedTime = toc

%% Define PIDs parameters for model
PC1x = 1.2;
IC1x = 0.08;
DC1x = 0.2;

PC2x = 2.0;
IC2x = 0.3;
DC2x = 0.3;

PC3x = 2.5;
IC3x = 0.4;
DC3x = 0.4;

PC4x = 2.7;
IC4x = 0.6;
DC4x = 0.5;

PC1y = 1.2;
IC1y = 0.08;
DC1y = 0.2;

PC2y = 2.0;
IC2y = 0.3;
DC2y = 0.3;

PC3y = 2.5;
IC3y = 0.4;
DC3y = 0.4;

PC4y = 2.7;
IC4y = 0.6;
DC4y = 0.5;

%% Run Model
Crane3D_DevDriv;
stop_time='60';
set_param('Crane3D_DevDriv','StopTime',stop_time);
%set_param('Crane3D_DevDriv','StopTime','40');
set_param('Crane3D_DevDriv/Constant','Value','waypoints');
set_param('Crane3D_DevDriv','SimulationCommand','update');
set_param('Crane3D_DevDriv','SimulationCommand','WriteDataLogs');
set_param('Crane3D_DevDriv','SimulationCommand','start');

pause(str2num(stop_time)+10)
%pause(130)

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

%pause(.25)

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
output_data = strcat(OutputPath,'/Results.csv');
csvwrite(char(output_data), [simout.TrajX, simout.TrajY(:,2), simout.CartX(:,2), simout.CartY(:,2), simout.AngleX(:,2), simout.AngleY(:,2), simout.DesX(:,2), simout.DesY(:,2)]);
%csvwrite('Results.csv', [TrajX, TrajY(:,2), CartX(:,2), CartY(:,2), CartdX(:,2), CartdY(:,2), AngleX(:,2), AngleY(:,2), AngledX(:,2), AngledY(:,2)]);
% 
% % Switch warnings relating to inputs and outputs not connected back on
% warning('on','Simulink:Engine:InputNotConnected');
% warning('on','Simulink:Engine:OutputNotConnected');
