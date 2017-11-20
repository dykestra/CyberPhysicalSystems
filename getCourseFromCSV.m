% Takes a csv file and returns an obstacle course:
%   obstacles: columns are x and y coord, one row per obstacles
%   targets: columns are x and y coord., one row per target
function [obstacles, targets] = getCourseFromCSV( file)
    M = csvread(file);               % Read data into array
    obstacles = M(M(:,3) == -1,1:2); % Third column = -1 means it's an obstacle
    targets = M(M(:,3) == 1,1:2);    % Third column = +1 means it's a target
end