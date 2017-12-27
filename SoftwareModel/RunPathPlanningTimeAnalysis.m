clear variables
close all
clc

%% Generate Montecarlo Scenarios
NUM_TARGETS = 3;
NUM_OBSTACLES = 100;
NUMBER_OF_SIMULATIONS = 50;
montecarlo_function(NUM_TARGETS,NUM_OBSTACLES,NUMBER_OF_SIMULATIONS,1);

%% Loop around all files
%directory = strcat('Verification/PathPlanningTest/Input/',int2str(NUM_TARGETS));
%directory = strcat(directory,'_');
%directory = strcat(directory,int2str(NUM_OBSTACLES));
%directory = strcat(directory,'/*.csv');
%files = dir(strcat(directory,'/*.csv'));
files = dir('Verification/PathPlanningTest/Input/*.csv');
for file = files'
    InputPath = strcat(string(file.folder) + '/' + string(file.name));
    Split = strsplit(string(file.name), '.');
    output_file = strcat('output_',int2str(NUM_TARGETS));
    output_file = strcat(output_file,'_');
    output_file = strcat(output_file,int2str(NUM_OBSTACLES));
    output_file = strcat(output_file,'.csv');
    OutputPath = strcat('Verification/PathPlanningTest/',output_file);
    %OutputPath = strcat('Verification/PathPlanningTest/output.csv');
    PathPlanningTimeAnalysis(InputPath, OutputPath)
end

