function val=cvowel()
name=input('Enter the filename:','s');
fid=fopen(name,'r');
t=fgets(fid);
a=[];
count=0;
while t~=-1
    for i=1:length(t)
        if t(i)=='a' || t(i)=='e' || t(i)=='i' || t(i)=='o' || t(i)=='u' || t(i)=='A' || t(i)=='E' || t(i)=='I' || t(i)=='O' || t(i)=='U'
            count=count+1;
        end
    end
    a=[a count];
    count=0;
    t=fgets(fid);
end
val=a;
fclose(fid);