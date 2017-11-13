function [ ] = PostSimAnalysis( MAP, waypoints, TrajX, TrajY, CartX, CartY, CartdX, CartdY, AngleX, AngleY, AngledX, AngledY, xRange, yRange )

%% Na magic function to plot
MAX_X = 50;
MAX_Y = 50;
axis([0 MAX_X+1 0 MAX_Y+1])
grid on;
hold on;

fig = figure(1);
for i=1:MAX_X
    for j=1:MAX_Y
        if(MAP(i,j) == -1)
            plot(i,j,'ro','MarkerFaceColor', 'r'); % obstacles 
        elseif (MAP(i,j) == 0)
             plot(i,j,'bd', 'MarkerFaceColor', 'b'); % target
        elseif (MAP(i,j) == 1)
             plot(i,j,'go', 'MarkerFaceColor', 'g'); % current position
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
title('Cart movement in x-y space')
xlim([0 50])
ylim([0 50])
xlabel('x');
ylabel('y');
saveas(fig,'Output_Fig/XY Space.jpg');

%% Further Analyses - Jukka
fig = figure(2);
subplot(2,2,1)
plot(CartX(:,1),CartX(:,2));
%line([cartX(1,1) cartX(end,1)],[x_in x_in],'LineWidth',1) % Wanted value
line([CartX(1,1) CartX(end,1)],[xRange(2) xRange(2)],'LineWidth',1) % Upper limit
title('Cart x values over time')
xlabel('Time');

subplot(2,2,2)
plot(CartY(:,1),CartY(:,2));
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
saveas(fig,'Output_Fig/Cart Analysis.jpg');

end

