function RunPathPlanningTimeAnalysis(InputFile,OutputFile)
    %% Load Variables and perform Path Planning
    tic;

    run('setup.m');
    MAP = txt2Map(InputFile);
    [waypoints] = path_planning(MAP);

    ElapsedTimePP = toc;

    display(InputFile)
    display(ElapsedTimePP)
    
    %% Save time information on csv
    %line = [InputFile string(ElapsedTimePP)];
    dlmwrite(OutputFile,ElapsedTimePP,'delimiter',',','-append');
end
