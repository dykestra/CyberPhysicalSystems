function heat_map = compute_heat_map( Grid )
%% Heatmap calculation
[MAX_X, MAX_Y] = size(Grid);
heat_map = zeros(MAX_X, MAX_Y);

[obs_cols, obs_rows] = find(Grid==-1);
obstacles = [obs_cols, obs_rows];

for i=1:MAX_X
    for j=1:MAX_Y
       if Grid(i,j) == -1
           heat_map(i,j) = 4;
       elseif Grid(i,j) == 2
           dist = dist_to_nearest_obstacle([i,j],obstacles);
           if dist < 4
               heat_map(i,j) = ceil(4 - dist);
           end
       end
    end
end

end

function min_dist = dist_to_nearest_obstacle( point , obstacles)

min_dist = intmax;
for i=1:size(obstacles,1)
    d = distance(obstacles(i,1), obstacles(i,2), point(1), point(2));
    if d < min_dist
        min_dist = d;
    end
end
end