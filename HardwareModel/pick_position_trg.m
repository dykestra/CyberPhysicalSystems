% Function to pick a position for a target
function [grid_out,t_list] = pick_position_trg(grid_in,t_list_in)
    type_num = 1;
        
    x = randi([3,47]);
    y = randi([3,47]);
    
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        t_list = t_list_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
        t_list(1,end+1) = x;
        t_list(2,end+1) = y;
    else % Recursive call if not clear on first go
        [grid_out,t_list] = pick_position_trg(grid_in,t_list_in);
    end
end