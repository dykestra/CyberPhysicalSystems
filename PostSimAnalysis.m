function [ ] = PostSimAnalysis( MAP, waypoints, TrajX, TrajY )

%% Na magic function to plot
MAX_X = 50;
MAX_Y = 50;
axis([0 MAX_X+1 0 MAX_Y+1])
grid on;
hold on;
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

end

