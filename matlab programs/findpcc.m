function [pccval]=findpcc(mat)
s2=size(mat,2);
k=[];
pccval=[];
for i=1:s2
    for j=1:s2
        k(j)=pc(mat(:,i)',mat(:,j)');
    end
    pccval=[pccval;k];
end
end