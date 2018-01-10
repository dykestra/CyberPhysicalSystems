% Open the controller and start it
open('GoHomeController');

mws = get_param('GoHomeController', 'modelworkspace');
mws.DataSource = 'MAT-File';
mws.FileName = 'GoHomeWorkspace';
mws.reload();

set_param(bdroot, 'UpdateModelReferenceTargets', 'force');
set_param(bdroot, 'SimulationCommand', 'start');

% Wait for the controller to end
while(~strcmp( get_param(bdroot,'SimulationStatus') , 'stopped'))
    pause(1);
end

close_system('GoHomeController', 0);