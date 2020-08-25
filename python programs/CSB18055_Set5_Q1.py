#CSB18055
#SET 5
#Question 1

#program to simulate a DFA that accepts string if (leangth of the string )% 4 = 2.

def dfa():
    s=input('enter a string consisting of 0,1 and 2\n')       #alphabet of the language is {0,1,2}
    c=0        #c denotes the states and the four states q0,q1,q2 and q3 are denoted by 0,1,2 and 3 respectively and the starting state is q0
    for i in range(0,len(s)):
        if (s[i]=='0' or s[i]=='1'or s[i]=='2') and c==0:                   #if in state q0 next symbol is 0 or 1 or 2 move to state q1
            c=1
        elif (s[i]=='0' or s[i]=='1'or s[i]=='2')and c==1:                 #if in state q1 next symbol is 0 or 1 or 2  move to state q2  
            c=2                                  # -In this state the value of (lenght of String)%4 is 2 which is accepted in the language.                               
        elif (s[i]=='0'or s[i]=='1'or s[i]=='2') and c==2:                 #if in state q2 next symbol is 0 or 1 or 2 move to state q3
            c=3
        elif (s[i]=='0' or s[i]=='1'or s[i]=='2')and c==3:                 #if in state q3 next symbol is 0 or 1 or 2  move to state q0
            c=0
        else:
            print('Invalid input --String can only have 0,1 and 2-- ')     #only 0,1,2 are accepted
            dfa()
            c=-1
            break;

    if c==2:                            #the final state set,F={q2}
        print('the string belongs to the language L')
    elif c!=-1:
        print('the string does not belong to the language L')
