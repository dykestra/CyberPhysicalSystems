run('setup.m');
load('5050Grid.mat')
[targets,waypoints] = path_planning(MAP);
options = simset('SrcWorkspace','current');
sim('Simscape_crane_software_model_RealSensors_R2016b',[],options)
PostSimAnalysis(MAP, waypoints, TrajX, TrajY);