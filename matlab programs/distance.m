function val=distance(a,mat)
b=[];
q={};
for j=1:size(mat,1)
   sum=0; 
   for i=1:size(mat,2)
       sum=sum+((a(i)-mat(j,i))*(a(i)-mat(j,i)));
   end
    q.value{j}=sqrt(sum);
    q.rank{j}=j;
    b=[b sqrt(sum)];
end  
b=sort(b);
disp(b)
for i=1:length(b)
    for j=1:length(b)
        if b(i)==q.value{j}
        disp(q.rank{j});
        end
    end
end
return;
end
    
    
