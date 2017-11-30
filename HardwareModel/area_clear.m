% Function to check if an area is clear
function isclear = area_clear(grid_in,x_in,y_in)
    for j = (y_in-1):(y_in)
       for i = (x_in-1):(x_in)
          if grid_in(i,j) ~= 0
              isclear = false;
              return
          end
       end
    end
    isclear = true;
end