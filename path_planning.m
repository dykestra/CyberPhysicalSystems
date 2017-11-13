function [targets, waypoints] = path_planning( Grid )
% given the obstacle course as a grid, return a list of targets and full
% list of waypoints

% get the coords of all targets
[targ_cols, targ_rows] = find( Grid==0 );
targets = [targ_cols, targ_rows];
n_targets = size(targets,1);

waypoints = [0,0];

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
    ind = remaining_targets~=visited_target;
    remaining_targets( ~any(ind,2), : ) = [];
   
end

targets(:) = targets(:)-1;
waypoints(:) = waypoints(:)-1;

end