for i=1:2
    a.Name{i}=input('Enter your Name:','s');
    a.RollNo{i}=input('Enter your RollNo:');
    a.CGPA{i}=input('Enter your CGPA:');
    a.Department{i}=input('Enter your Department:','s');
    a.Semester{i}=input('Enter your Semester:');
end  
display('Name of students with CGPA>7.5 are:');
for i=1:3
    if a.CGPA{i}>7.5
        display(a.Name{i});
    end
end    