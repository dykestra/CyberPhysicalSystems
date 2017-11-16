function MAP = txt2Map(filepath)

fileID = fopen(filepath,'r');
formatID = '%d %d %s';
sizeID = [3 Inf];
A = fscanf(fileID,formatID,sizeID);
A=A';
fclose(fileID);

MAP=2*ones(50,50);
MAP(1,1)=1;

target=double('t');
obstacle=double('o');

[xt,yt]=find(A==target);
[xo,yo]=find(A==obstacle);

for i=1:1:length(xt)
    aux1=A(xt(i),1);
    aux2=A(xt(i),2);
    MAP(aux1,aux2)=0;
end;

for j=1:1:length(xo)
    aux3=A(xo(j),1);
    aux4=A(xo(j),2);
    MAP(aux3,aux4)=-1;
end;
