function waypoints = path_to_waypoints(path, plotgrid)
% Takes a list of coordinates and returns a shorter list of waypoints

if nargin < 2
    plotgrid = 1;
end

len = size(path,1);
waypoints = []; %size of waypoints unknown until completion
prev_dir = path(2,:) - path(1,:); % last direction [xdir, ydir]
prev_point = path(2,:);

for i=3:len
    next_point = path(i,:);
    next_dir = next_point-prev_point;
    if ~isequal(next_dir,prev_dir)
        waypoints(end+1,:) = prev_point; % add to waypoint if direction changes
    end
    prev_point = next_point;
    prev_dir = next_dir;
end

waypoints(end+1,:) = path(end,:); % always add end target to waypoints

% optional - plot waypoints
if plotgrid
    for i=1:size(waypoints,1)
        plot(waypoints(i,1)+.5,waypoints(i,2)+.5,'rx','MarkerFaceColor', 'r');
    end
end
end