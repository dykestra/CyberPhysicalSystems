clear variables
close all
clc

%% Generate Montecarlo Scenarios
montecarlo_inputs;
clear variables 

ModelName = 'Simscape_crane_software_model_RealSensors_R2016b';

%% Loop around all files
files = dir('MontecarloScenarios/Input/*.csv');
for file = files'
    InputPath = strcat(string(file.folder) + '/' + string(file.name));
    Split = strsplit(string(file.name), '.');
    OutputPath = strcat('MontecarloScenarios/Output/' + Split(1));
    RunModel(InputPath, OutputPath, ModelName)
    
    % Switch off the Mechanics editor opening for later scenarios
    % - so the first scenario will be opened as usual, while others not, as
    %   there is not enough time to show them anyway before new scenario is
    %   run -- this also aids Matlab stability on Ubuntu
    %set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','off');
end

% Switch Mechanics editor opening back on
%set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','on');
