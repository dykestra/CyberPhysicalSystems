function waypoints = path_to_waypoints(path)
% Takes a list of coordinates and returning a shorter list of waypoints

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
end