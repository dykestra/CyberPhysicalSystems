function [ scores ] = testCrane( hardware, runTime )
%TESTCRANE Summary of this function goes here
%   Detailed explanation goes here

% Add this directory to the path
addpath(pwd);

%% Locate the obstacle courses
courses = findCourses('Courses');
numCourses = length(courses);


%% Locate the team files
teamFiles = findTeamFiles('TeamData');
numTeams = length(teamFiles);


%% Create some data types to store the results
scoreMatrix = zeros(numTeams);
obsMatrix = zeros(numTeams);
tarMatrix = zeros(numTeams);
timeMatrix = zeros(numTeams);


%% Iterate over each obstacle course
for courseNum=1:1:numCourses;
    % Get the pertinent data for the course
    disp(['Running obstacle course ', courses(courseNum).name]);
    obstacles = courses(courseNum).obstacles;
    targets = courses(courseNum).targets;
    
    % Iterate over each team for this obstacle course
    for teamNum=1:1:numTeams
        clear team;
        team = teamFiles(teamNum);
        disp(['  Running team ', team.name]);
    
        % Navigate to the team directory
        runningDir = cd(team.direc);

        % Run the team setup file and time it
        tic;
        simSetup(obstacles, targets, hardware);
        setupTime = toc;
        disp(['    Setup ran in ', num2str(setupTime), 's']);

        % Choose the model to execute depending on the simulation
        if (hardware)
            simModel = team.hardwareFile;
        else
            simModel = team.softwareFile;
        end

        % Open the simulink model
        open(simModel);

        % Set the model workspace to be based on the .mat file created in the
        % setup function
        mws = get_param(simModel, 'modelworkspace');
        mws.DataSource = 'MAT-File';
        mws.FileName = 'workspace';
        mws.reload();
        
        % Set the maximum time for the simulation to run to be 10 minutes
        runTimeSec = runTime - setupTime;
        set_param(bdroot, 'StopTime', num2str(runTimeSec));
        
        if (hardware)
            % If the hardware model is in use do update and start
            set_param(bdroot, 'UpdateModelReferenceTargets', 'force');
            set_param(bdroot, 'SimulationCommand', 'start');
            
            % Wait for the simulation to run
            while(~strcmp( get_param(bdroot,'SimulationStatus') , 'stopped'))
                pause(1);
            end
            
            simout.yout = evalin('base', 'yout');
            simout.yout.signals.blockName = '/output';
        else
            % If the software model is in use, use the sim command
            simout = sim(simModel, 'ReturnWorkspaceOutputs','on');
        end
        
        % Close the model without saving
        close_system(simModel, 0);
        
        if ( strcmp( class(simout), 'Simulink.SimulationOutput') )
            simTemp = simout;
            clear simout;
            simout.tout = simTemp.get('tout');
            simout.yout = simTemp.get('yout');
        end
        
        % Navigate back to the running directory
        cd(runningDir);
        
        % Score the run
        [score, obsHit, tarReached, timeComplete] = getScore(simout, obstacles, targets, setupTime);
        
        disp(['    Targets Reached: ', num2str(tarReached)]);
        disp(['    Obstacles Hit:   ', num2str(obsHit)]);
        disp(['    Time Taken:      ', num2str(timeComplete)]);
        disp(['    Overall Score:   ', num2str(score)]);
        
        % Save the score data
        scoreMatrix( courseNum, teamNum ) = score;
        obsMatrix( courseNum, teamNum )   = obsHit;
        tarMatrix( courseNum, teamNum )   = tarReached;
        timeMatrix( courseNum, teamNum )  = timeComplete;
        
        % Move the crane back to the starting position
        if ( hardware )
            cd('GoHomeController');
            
            % Open the Go Home controller
            open('GoHomeController');
            
            % Load its workspace
            mws = get_param('GoHomeController', 'modelworkspace');
            mws.DataSource = 'MAT-File';
            mws.FileName = 'GoHomeWorkspace';
            mws.reload();
            
            % Start and then wait for the crane to return home
            set_param(bdroot, 'UpdateModelReferenceTargets', 'force');
            set_param(bdroot, 'SimulationCommand', 'start');
            while(~strcmp( get_param(bdroot,'SimulationStatus') , 'stopped'))
                pause(1);
            end
            
            close_system('GoHomeController', 0);
        end
        
        % Change back to the running directory
        cd(runningDir);
    end
    
end

scores = scoreMatrix;

end


