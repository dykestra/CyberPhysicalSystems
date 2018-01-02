clear variables
close all
clc

%% Generate Verification courses
% Delete old ones
files = dir('Verification/Input/*.csv');
for file = files'
    %delete(char( strcat(string(file.folder) + '/' + string(file.name)) ))
    delete(char( strcat('Verification/Input/',file.name) ))
end
files = dir('Verification/Output/*.jpg');
for file = files'
    delete(char( strcat('Verification/Output/',file.name) ))
end

% Create files
%movement_verification;
filepath = 'Verification/Input/scenario';
movement_verification(filepath);
clear variables 

ModelName = 'Simscape_crane_software_model_2Contr';
orig_stop_time = get_param(ModelName, 'StopTime');
set_param(ModelName, 'StopTime', '80');


%% Loop around all files
files = dir('Verification/Input/*.csv');
for file = files'
    InputPath = strcat('Verification/Input/',file.name);
    Token = strtok(file.name,'.'); %2016a
    OutputPath = strcat('Verification/Output/',Token);
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
