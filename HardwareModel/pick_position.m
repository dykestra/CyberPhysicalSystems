% Function to pick a position for an object (target/obstacle)
function grid_out = pick_position(grid_in,type_in)
    if type_in == 't'
        type_num = 1;
    else
        type_num = -1;
    end

    x = randi([3,47]);
    y = randi([3,47]);
    
    if area_clear(grid_in,x,y)
        grid_out = grid_in;
        for j = (y-1):y
            for i = (x-1):x
                grid_out(i,j) = 2;
            end
        end
        grid_out(x,y) = type_num;
    else % Recursive call if not clear on first go
        grid_out = pick_position(grid_in,type_in);
    end
end