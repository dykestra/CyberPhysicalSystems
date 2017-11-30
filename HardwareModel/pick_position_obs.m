% Function to pick a position for an obstacle
function grid_out = pick_position_obs(grid_in,t_list,max_dist_ot)
    type_num = -1;
    x_list = [];
    y_list = [];
    x = 0;
    y = 0;
        
    % Use the t_list of x and y values to
    for i = 1:size(t_list,2)
        x_curr = t_list(1,i);
        y_curr = t_list(2,i);
        lst = linspace(x_curr-max_dist_ot, x_curr+max_dist_ot,2*max_dist_ot+1);
        x_list = cat(2,x_list,lst);

        lst = linspace(y_curr-max_dist_ot, y_curr+max_dist_ot,2*max_dist_ot+1);
        y_list = cat(2,y_list,lst);
    end
    x_list = process_list(x_list);
    y_list = process_list(y_list);
    
    x = datasample(x_list,1);
    y = datasample(y_list,1);
        
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
    else % Recursive call if not clear on first go
        grid_out = pick_position_obs(grid_in,t_list,max_dist_ot);
    end
end