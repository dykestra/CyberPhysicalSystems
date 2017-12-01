function [waypoints] = path_planning( Grid )
% given the obstacle course as a grid, return a list of targets and full
% list of waypoints

% get the coords of all targets
[targ_cols, targ_rows] = find( Grid==0 );
targets = [targ_cols, targ_rows];
n_targets = size(targets,1);

waypoints = [1,1];

remaining_targets = targets;

for r=1:n_targets
    % find min cost path from curr position
    min_path = [];
    min_path_cost = intmax;

    for t=1:size(remaining_targets,1)
        % remove other targets from grid
        t_grid = Grid;
        t_grid(Grid==0) = 2;
        t_grid(remaining_targets(t,1), remaining_targets(t,2)) = 0;

        t_path = A_Star(t_grid,0);
        t_cost = calculate_cost(t_path);
        if min_path_cost > t_cost
            min_path_cost = t_cost;
            min_path = t_path;
        end
    end
    
    % add to waypoints
    waypoints = vertcat(waypoints, path_to_waypoints(min_path,0));
    
    visited_target = min_path(end,:);
    
    % set current position to visited target
    Grid(Grid==1) = 2;
    Grid(visited_target(1), visited_target(2)) = 1;
    
    % remove visited target from remaining_targets
    for o=1:size(remaining_targets,1)
        if visited_target == remaining_targets(o,:)
            remaining_targets(o,:) = [];
            break
        end
    end
   
end

waypoints = [waypoints, find_nearest_obstacles(waypoints, Grid)];

targets(:) = targets(:)-1;
waypoints(:) = waypoints(:)-1;

is_target = zeros(size(waypoints,1),1);
for i=1:size(waypoints,1)
    for j=1:size(targets,1)
        if waypoints(i,1:2)==targets(j,:)
            is_target(i) = 1;
        end
    end
end

waypoints = [waypoints is_target];

end

function nearest_obstacles = find_nearest_obstacles( waypoints, Grid )

nearest_obstacles = zeros(size(waypoints));
[obs_cols, obs_rows] = find(Grid==-1);
obstacles = [obs_cols, obs_rows];

for i=1:size(waypoints,1)
    min_dist = intmax;
    for j=1:size(obstacles,1)
        d = distance(obstacles(j,1),obstacles(j,2),waypoints(i,1),waypoints(i,2));
        if d < min_dist
            nearest_obstacles(i,:) = obstacles(j,:);
            min_dist = d;
        end
    end
end

end