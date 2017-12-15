function [ ] = PostSimAnalysis( OutputPath, MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, xRange, yRange, DesiredX, DesiredY)

%% Create required folders for PostSim Analysis
if not(exist(char(OutputPath),'dir')) % my Matlab version needs char array
  mkdir(char(OutputPath));
end

%% Close all previous figures
close all

%% Na magic function to plot
MAX_X = 50;
MAX_Y = 50;
axis([0 MAX_X+1 0 MAX_Y+1])
grid on;
hold on;

fig = figure(1);
%set(fig, 'Visible', 'off'); %suppress displaying the figure
for i=1:MAX_X
    for j=1:MAX_Y
        if(MAP(i,j) == -1) % obstacles
            rectangle('Position',[i-2,j-2,2,2],'FaceColor','r','EdgeColor','r')
        elseif (MAP(i,j) == 0) % targets
            rectangle('Position',[i-2,j-2,2,2],'EdgeColor','b')
        elseif (MAP(i,j) == 1)
             plot(i-1,j-1,'go', 'MarkerFaceColor', 'g'); % current position
        end
    end
end

j=size(waypoints,1);
p=plot(waypoints(j,1),waypoints(j,2),'bo');
j=j-1;
for i=j:-1:1
    pause(.25);
    set(p,'XData',waypoints(i,1),'YData',waypoints(i,2));
    drawnow ;
end
plot(waypoints(:,1),waypoints(:,2));

%% Our magic plotting function
TrajX(:,2) = 100*TrajX(:,2);
TrajY(:,2) = 100*TrajY(:,2);
plot(TrajX(:,2),TrajY(:,2));
title('Payload movement in x-y space')
xlim([0 50])
ylim([0 50])
xlabel('x');
ylabel('y');
%saveas(fig,char( strcat(string(OutputPath) + '/XY Space.jpg') ));
saveas(fig,char( strcat(OutputPath,'/XY Space.jpg') ));

%% Further Analyses - Jukka
fig = figure(2);
%set(fig, 'Visible', 'off'); %suppress displaying the figure
subplot(2,2,1)
plot(CartX(:,1),CartX(:,2));  hold on;
plot(DesiredX(:,1),DesiredX(:,2));
%line([cartX(1,1) cartX(end,1)],[x_in x_in],'LineWidth',1) % Wanted value
%line([CartX(1,1) CartX(end,1)],[xRange(2) xRange(2)],'LineWidth',1) % Upper limit
title('Cart x values over time')
xlabel('Time');

subplot(2,2,2)
plot(CartY(:,1),CartY(:,2));  hold on;
plot(CartY(:,1),DesiredY(:,2));
title('Cart y values over time')
xlabel('Time');

subplot(2,2,3)
plot(CartdX(:,1),CartdX(:,2));
title('dx values over time')
xlabel('Time');

subplot(2,2,4)
plot(CartdY(:,1),CartdY(:,2));
title('dy values over time')
xlabel('Time');
%saveas(fig,char( strcat(string(OutputPath),'/Cart Analysis.jpg') ));
saveas(fig,char( strcat(OutputPath,'/Cart Analysis.jpg') ));


% Figures of the angles
fig = figure(3);
subplot(2,1,1)
plot(AngleX(:,1),AngleX(:,2));
title('X angle values over time')
xlabel('Time');

subplot(2,1,2)
plot(AngleY(:,1),AngleY(:,2));
title('Y angle values over time')
xlabel('Time');


% Figures of the Payload X and Y versus the desired values
fig = figure(4);
subplot(2,1,1)
plot(TrajX(:,1),TrajX(:,2));
hold on;
plot(TrajX(:,1),DesiredX(:,2)*100);
title('Payload X values over time')
xlabel('Time');

subplot(2,1,2)
plot(TrajY(:,1),TrajY(:,2));
hold on;
plot(TrajY(:,1),DesiredY(:,2)*100);
title('Payload Y values over time')
xlabel('Time');




%% Scatterplot of x and y, with time as colour input
%% works as: scatter(x, y, circle_size, colour, 'filled')
%colours = set_colour( TrajX(:,1) );

%% Plotting a scatterplot with varying colours
%figure(5)
%sz = 10;
%scatter(TrajX(:,2), TrajY(:,2), sz, colours, 'filled')
%xlim([0 50])
%ylim([0 50])
%title('Payload movement in x-y space')

end


% Function to set plotting colour intervals based on time
function col = set_colour(input_array)
    col = input_array;

    % Progressing values, but only switching every second
    col(:) = fix(col(:)); % truncate the values to integers

    % Switching between two values only
    for i=1:size(input_array)
        j = col(i);
           
        % Switching between two values
        if (mod(j,2) == 0)
            col(i) = 1;
        else
            col(i) = 10;
        end
    end
end
