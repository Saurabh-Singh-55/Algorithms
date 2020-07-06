function []=discrete(r)
b=sort(r);
w=input('Enter the number of elements in each bin:');
if rem(length(r),w)==0
    bin=floor(length(r)/w);
else
    bin=floor(length(r)/w)+1;
end
a=zeros(bin,w);
m=1;
n=1;
for i=1:length(r)
    a(m,n)=b(i);
    if rem(i,w)==0
        m=m+1;
        n=1;
    end
    if rem(i,w)~=0
    n=n+1;
    end
end
disp(a);
end
    
        
    
    

    