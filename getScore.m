%% Calculate Score based on targets, obstacles, and time
function [score, obsHit, tarReached, timeComplete] = getScore( simout, obstacles, targets, setupTime)
    %% Some parameters
    delta = 0.01; % Size of targets and obstacles
    lstring = 0.3;     % Length of pendulum string
    %% Get trajectory from simulink data
    j = 0;
    for i = 1:size(simout.yout.signals,2)
        if ~isempty( strfind(simout.yout.signals(i).blockName, '/output') )
            j = i;
        end
    end
    if j == 0
        printf('No output signal named "output" specified')
    end
    
    timeV = simout.yout.time;
    cartX = simout.yout.signals(j).values(:,1);
    cartY = simout.yout.signals(j).values(:,3);
    alphaX = simout.yout.signals(j).values(:,5);
    alphaY = simout.yout.signals(j).values(:,7);
    
    %% Calculate payload trajectory
    
     payloadX = cartX + sin(alphaX)*lstring;
     payloadY = cartY + sin(alphaY)*lstring;

%     payloadX = cartX + (sin(alphaX+pi/2).*sin(alphaY)).*lstring;
%     payloadY = cartY + cos(alphaX+pi/2)*lstring;
    
    
    %% Plot stuff if desired
    hold off
    plot(payloadX, payloadY)
    hold on
    for i = 1:size(targets,1)            
        rectangle('Position',[(targets(i,1)-1)/100 (targets(i,2)-1)/100 2*delta 2*delta])
    end
    for i = 1:size(obstacles,1)
        delta = 0.01;
        rectangle('Position',[(obstacles(i,1)-1)/100 (obstacles(i,2)-1)/100 2*delta 2*delta],'FaceColor','red')
    end
    
    %% Calculate score
    tarN = 0;
    obsN = 0;
    tComplete = 0;
    tMax = 10*60;
    
    % Check how many targets were hit
    for i = 1:size(targets,1)
       target = targets(i,:); 
       target = target/100;
       
       % Index of payload positions within the target area
       ind = (payloadX(:,1) <= target(1) + delta) & (payloadX(:,1) >= target(1) - delta ) & (payloadY(:,1) <= target(2) + delta) & (payloadY(:,1) >= target(2) - delta );       
       
       if(sum(ind) > 0)
            tarN = tarN + 1; % Target was hit
            tReached = min(timeV(ind,1)); % The first point in time at which the target was hit       
            if(tReached >= tComplete) 
                tComplete = tReached; % The point in time at which the last target was hit
            end
       end
    end
    
    % Add the setup time to the scoring time
    tComplete = tComplete + setupTime;
    
    if(tarN ~= size(targets, 1))
        tComplete = tMax; % Set tComplete to tMax if not all targets were reached
    else
        tComplete = min(tComplete, tMax); % Check if time limit was reached
    end
    
    % Check how many obstacles were hit
    for i = 1:size(obstacles,1)
       obstacle = obstacles(i,:); 
       obstacle = obstacle/100;
       
       % Index of payload positions within the obstacle area
       ind = (payloadX(:,1) <= obstacle(1) + delta) & (payloadX(:,1) >= obstacle(1) - delta) & (payloadY(:,1) <= obstacle(2) + delta) & (payloadY(:,1) >= obstacle(2) - delta);
       
       if(sum(ind) > 0)
          obsN = obsN + 1; % Obstacle was hit
       end
    end
    
    tarReached = tarN;
    obsHit = obsN;
    timeComplete = tComplete;
    % Calculate score
    score = (1 + size(targets,1) - tarN + obsN)*tComplete;
end