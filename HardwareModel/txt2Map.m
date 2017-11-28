function MAP = txt2Map(filepath)

M = csvread(filepath);               % Read data into array
obstacles = M(M(:,3) == -1,1:2); % Third column = -1 means it's an obstacle
targets = M(M(:,3) == 1,1:2);    % Third column = +1 means it's a target

MAP=2*ones(50,50);
MAP(1,1)=1;

 for i=1:1:length(obstacles)
     aux1=obstacles(i,1)+1;
     aux2=obstacles(i,2)+1;
     MAP(aux1,aux2)=-1;
 end;

for j=1:1:length(targets)
    aux3=targets(j,1)+1;
    aux4=targets(j,2)+1;
    MAP(aux3,aux4)=0;
end;
