clear variables
close all
clc

%% Generate Verification courses
% Delete old ones
files = dir('Verification/Input/*.csv');
for file = files'
    delete(char( strcat(string(file.folder) + '/' + string(file.name)) ))
end
files = dir('Verification/Output/*.jpg');
for file = files'
    delete(char( strcat(string(file.folder) + '/' + string(file.name)) ))
end

% Create files
movement_verification;
clear variables 

%ModelName = 'Simscape_crane_software_model_SingleContr_R2016b';%'Simscape_crane_software_model_RealSensors_R2016b';
ModelName = 'Simscape_crane_software_model_RealSensors_R2016b';
orig_stop_time = '180';%get_param(ModelName, 'StopTime');
set_param(ModelName, 'StopTime', '80');


%% Loop around all files
files = dir('Verification/Input/*.csv');
for file = files'
    InputPath = strcat(string(file.folder) + '/' + string(file.name));
    Split = strsplit(string(file.name), '.');
    OutputPath = strcat('Verification/Output/' + Split(1));
    display(file.name)
    RunModelVerification(InputPath, OutputPath, ModelName)
    
    % Switch off the Mechanics editor opening for later scenarios
    % - so the first scenario will be opened as usual, while others not, as
    %   there is not enough time to show them anyway before new scenario is
    %   run -- this also aids Matlab stability on Ubuntu
    set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','off');
end

% Switch Mechanics editor opening back on
set_param(ModelName,'SimMechanicsOpenEditorOnUpdate','on');

% Reset the original model stop time
set_param(ModelName, 'StopTime',orig_stop_time);
