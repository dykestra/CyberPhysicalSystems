function [ teams ] = findTeamFiles( teamDataDir)
%FINDTEAMFILES Find the paths to the team files
%
%

%% Navigate to the team directory and get the directory listing
origDir = cd(teamDataDir);
listing = dir();

%% Iterate through the directory to find the team directories
k = 1;
for( i=1:1:length(listing) )
    % Ignore anything that isn't a directory
    if ( listing(i).isdir == 0 )
        continue
    end
    
    % Ignore the . directory entry
    if ( strcmp(listing(i).name, '.') )
        continue
    end
    
    % Ignore the .. directory entry
    if ( strcmp(listing(i).name, '..') )
        continue
    end
    
    dirListing{k} = listing(i).name;
    k = k+1;
end

%% Iterate through the team directories
for( i=1:1:length(dirListing) )
    cd( dirListing{i} );
    
    clear temp;
    
    temp.name = dirListing{i};
    temp.direc = pwd;
    temp.hardwareFile = [];
    temp.softwareFile = [];
    temp.setupFile = [];
    listing = dir();
    
    % Go through every file in the directory
    for ( k=1:1:length(listing) )
        % Skip directories
        if (listing(k).isdir == 1)
            continue
        end
        
        hard = regexpi( listing(k).name, '[\s\S]*[hH]ardware[\s\S]*\.(mdl|slx)$' );
        soft = regexpi( listing(k).name, '[\s\S]*[sS]oftware[\s\S]*\.(mdl|slx)$' );
        setu = regexpi( listing(k).name, 'simSetup.m$' );
        
        % It is the hardware file if the string matched
        if ( ~isempty(hard) )
            [~, temp.hardwareFile, ~] = fileparts(listing(k).name);
        end
        
        % It is the software file if the string matched
        if ( ~isempty(soft) )
            [~, temp.softwareFile, ~] = fileparts(listing(k).name);
        end
        
        % It is the setup function if the string matched
        if ( ~isempty(setu) )
            temp.setupFile = listing(k).name;
        end
    end
    
    if ( isempty( temp.hardwareFile) )
        cd(origDir);
        error(['Unable to find hardware simulation file for team ', temp.name]);
    end
    if ( isempty( temp.softwareFile) )
        cd(origDir);
        error(['Unable to find software simulation file for team ', temp.name]);
    end
    if ( isempty( temp.setupFile) )
        cd(origDir);
        error(['Unable to find simulation setup function for team ', temp.name]);
    end
    
    
    teams(i) = temp;
    cd('..');
end

cd(origDir);

end