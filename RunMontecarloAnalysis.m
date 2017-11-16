clear variables
close all
clc

%% Generate Montecarlo Scenarios
montecarlo_inputs;

%% Loop around all files
files = dir('MontecarloScenarios/Input/*.csv');
for file = files'
    InputPath = strcat(string(file.folder) + '/' + string(file.name));
    Split = strsplit(string(file.name), '.');
    OutputPath = strcat('MontecarloScenarios/Output/' + Split(1));
    RunModel(InputPath, OutputPath)
end
