% Simulation loop over Simscape model

% Run with parameter value struct
%paramNameValStruct.x    = 0.5;
%paramNameValStruct.y    = 0.5;

% Using constant inputs
%x_in = 0.35;
%y_in = 0.35;
%simOut = sim('Simscape_crane_software_model');

%Run with existing parameter values
simOut = sim('Simscape_crane_software_model_RealSensors_R2016b');

% PLOT outputs from the Scope blocks
% NOTE: have to specify in Scope config:
%       switch on "Log data to workspace", and give the name of variable,
%       AND specify the type to be "structure with time"
figure(1)
subplot(2,2,1)
plot(cartX(:,1),cartX(:,2));
%line([cartX(1,1) cartX(end,1)],[x_in x_in],'LineWidth',1) % Wanted value
line([cartX(1,1) cartX(end,1)],[xRange(2) xRange(2)],'LineWidth',1) % Upper limit
title('Cart x values over time')
xlabel('Time');

subplot(2,2,2)
plot(cartY(:,1),cartY(:,2));
title('Cart y values over time')
xlabel('Time');

subplot(2,2,3)
plot(velX(:,1),velX(:,2));
title('dx values over time')
xlabel('Time');

subplot(2,2,4)
plot(velY(:,1),velY(:,2));
title('dy values over time')
xlabel('Time');

% PLOT x and y
figure(2)
plot(cartX(:,2),cartY(:,2));
title('Cart movement in x-y space')
xlim([0 0.5])
ylim([0 0.5])
xlabel('x');
ylabel('y');


% Scatterplot of x and y, with time as colour input
% works as: scatter(x, y, circle_size, colour, 'filled')

% Setup values to plot
plX = TrajX;
plY = TrajY;
plX(:,2) = 100*TrajX(:,2); 
plY(:,2) = 100*TrajY(:,2);

colours = set_colour( plX(:,1) );

% Plotting
figure(3)
sz = 10;
scatter(plX(:,2), plY(:,2), sz, colours, 'filled')
xlim([0 50])
ylim([0 50])
title('Payload movement in x-y space')



% Function to set plotting colour intervals based on time
function col = set_colour(input_array)
    col = input_array;

    % Progressing values, but only switching every second
    col(:) = fix(col(:)); % truncate the values to integers

    % Switching between two values only
    %for i=1:size(input_array)
    %    j = col(i);
    %   
    %    % Switching between two values
    %    if (mod(j,2) == 0)
    %        col(i) = 1;
    %    else
    %        col(i) = 10;
    %    end
    %    % Progressing across values, but only switching every second
    %    %col(i) = j
    %end
end

