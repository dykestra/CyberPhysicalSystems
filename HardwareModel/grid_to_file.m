% Function to convert a grid into a text file
function [] = grid_to_file(grid_in,filename)
    for i=1:50
        for j = 1:50
            if abs(grid_in(i,j)) == 1
                line = [j i grid_in(i,j)];
                dlmwrite(filename,line,'delimiter',',','-append');
            end             
        end
    end
end