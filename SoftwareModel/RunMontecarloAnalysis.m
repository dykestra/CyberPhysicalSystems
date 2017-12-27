clear variables
close all
clc

%% Generate Montecarlo Scenarios
%montecarlo_inputs;
%NUM_TARGETS = 3;
%NUM_OBSTACLES = 3;
%NUMBER_OF_SIMULATIONS = 50;
%montecarlo_function(NUM_TARGETS,NUM_OBSTACLES,NUMBER_OF_SIMULATIONS,0);

clear variables 

ModelName = 'Simscape_crane_software_model_NPNC_2016a';%'Simscape_crane_software_model_RealSensors_R2016b';
%ModelName = 'Simscape_crane_software_model_SingleContr_R2016b';%'Simscape_crane_software_model_RealSensors_R2016b';
%ModelName = 'Simscape_crane_software_model_RealSensors_R2016b';

%% Loop around all files
files = dir('MontecarloScenarios/Input/*.csv');
FOLDER = 'MontecarloScenarios/Input/'; %2016a
for file = files'
    %InputPath = strcat(string(file.folder) + '/' + string(file.name));
    %Split = strsplit(string(file.name), '.');
    %OutputPath = strcat('MontecarloScenarios/Output/' + Split(1));
    InputPath = strcat(FOLDER,file.name); %2016a
    fname = file.name
    Split = strsplit(char(fname),'.') %2016a
    OutputPath = strcat('MontecarloScenarios/Output/',Split(1)) %2016a
    RunModel(InputPath, OutputPath, ModelName)
    
    % Switch off the Mechanics editor opening for later scenarios
    % - so the first scenario will be opened as usual, while others not, as
    %   there is not enough time to show them anyway before new scenario is
    %   run -- this also aids Matlab stability on Ubuntu
    set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','off');
end

% Switch Mechanics editor opening back on
set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','on');
