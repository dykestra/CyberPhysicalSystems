clear variables
close all
clc

%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_RealSensors_R2016b')
%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_SingleContr_R2016b')
RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_RealSensors_R2016a')
%RunModel('MontecarloScenarios/Input/scenario1.txt','MontecarloScenarios/Output/scenario1')