function [ course ] = findCourses( searchDir )

%% Navigate to the search directory
originalDir = cd(searchDir);


%% Loop through every entry in the directory
k = 1;
listing = dir();
for( i=1:1:length(listing) )
    % Ignore anything that is a directory
    if ( listing(i).isdir == 1 )
        continue;
    end
    
    % See if the name of the file has .csv in the name as the extension
    cour = regexpi( listing(i).name, '[\s\S]*\.csv' );
    
    % If it doesn't have the right extension, skip it
    if ( isempty(cour) )
        continue;
    end
    
    %% Save pertinent details
    course(k).name = listing(i).name;
    
    % Get the obstacle course from the file
    courseFile = [pwd, filesep, listing(i).name];
    [course(k).obstacles, course(k).targets] = getCourseFromCSV(courseFile);    
    
    k = k+1;
end


cd(originalDir);

end