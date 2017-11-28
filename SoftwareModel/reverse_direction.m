function reversed = reverse_direction(path)
    
reversed = zeros(size(path));
len = size(path,1);
for i=1:len
    reversed(len - i + 1,:) = path(i,:);
end

end