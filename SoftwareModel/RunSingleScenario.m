clear variables
close all
clc

%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_RealSensors_R2016b')
%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_SingleContr_R2016b')
%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_RealSensors_R2016a')
%RunModelVerification('MontecarloScenarios/Input/scenario1.csv','MontecarloScenarios/Output/scenario1', 'Simscape_crane_software_model_RealSensors_R2016b')
%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_NPNC_2016a')
%RunModel('SingleScenarios/Input/scenario1.csv', 'SingleScenarios/Output', 'Simscape_crane_software_model_2Contr')
%RunModelVerification('MontecarloScenarios/Input/scenario1.csv','MontecarloScenarios/Output/scenario1', 'Simscape_crane_software_model_NPNC_2016a')
%RunModel('MontecarloScenarios/Input/scenario1.csv', 'MontecarloScenarios/Output/scenario1', 'Simscape_crane_software_model_NPNC_2016a')
RunModel('MontecarloScenarios/Input/scenario1.csv', 'MontecarloScenarios/Output/scenario1', 'Simscape_crane_software_model_2Contr')