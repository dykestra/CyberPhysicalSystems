function [ is_satisfied ] = check_properties( sim_output, targets )
%Function to check if all properties are satisfied
%   Returns 1 if all satisfied, and 0 if not
    is_satisfied = 0;
    coords_ok = 0;
    angles_ok = 0; 
    
    MAX_ANGLE = pi/4; % CHECK WHAT THIS SHOULD BE!
    
    TrajX = sim_output.get('TrajX');
    TrajY = sim_output.get('TrajY');
    AngleX = sim_output.get('AngleX');
    AngleY = sim_output.get('AngleY');
    TrajX = TrajX(:,2);
    TrajY = TrajY(:,2);
    AngleX = AngleX(:,2);
    AngleY = AngleY(:,2);

    % Checking all targets are reached
    for row=1:size(targets,1)
        target=targets(row,:)/100;
        for xi = 1:size(TrajX)
            if (target(1)-0.01 < TrajX(xi)) && (TrajX(xi) < target(1)+0.01) && (target(2)-0.01 < TrajY(xi)) && (TrajY(xi) < target(2)+0.01)
                coords_ok = coords_ok + 1;
                break
            end
        end
    end
    if coords_ok == size(targets,1) % If all targets have had an OK
        coords_ok = 1;
    else
        coords_ok = 0;
    end

    
    % Checking angles are not beyond targets are reached
    for i = 1:size(AngleX)
        if abs(AngleX(i)) > MAX_ANGLE || abs(AngleY(i)) > MAX_ANGLE 
            AngleX(i)
            AngleY(i)
            break
        end
        angles_ok = 1;
    end
    
    
    % If all satisfied, return 1
    if coords_ok==1 && angles_ok==1
        is_satisfied = 1;
    end
end

