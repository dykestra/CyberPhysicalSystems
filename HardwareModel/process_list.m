% Function to cut out indices that are not needed
function list_out = process_list(list_in)
    list_out = unique(sort(list_in));
    new_start = find(list_out==3);
    new_end   = find(list_out==47);

    if isempty(new_start)
        new_start = 0;
    end

    if isempty(new_end)
        new_end = length(list_out);
    end
    list_out = list_out(new_start:new_end);
end