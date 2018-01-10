function MAP = info2Map(in_obstacles, in_targets)

obstacles = in_obstacles;
targets = in_targets;

% Change to have offset of 1 (to match Johannes' numbering)
%obstacles = in_obstacles + 1;
%targets = in_targets + 1;

MAP=2*ones(50,50);
MAP(1,1)=1;

 for i=1:1:size(obstacles,1)
     aux1=obstacles(i,1)+1;
     aux2=obstacles(i,2)+1;
     MAP(aux1,aux2)=-1;
 end;

for j=1:1:size(targets,1)
    aux3=targets(j,1)+1;
    aux4=targets(j,2)+1;
    MAP(aux3,aux4)=0;
end;
