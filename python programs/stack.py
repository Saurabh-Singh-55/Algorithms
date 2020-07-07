def bar():
    s=input('enter the data')
    stack=[]
    p=0
    for i in range(0,len(s)-1):
        p=s[i]
        if i==0:
            stack.append(p)
        elif(p=='(' or p=='{'):
            stack.append(p)
        elif(stack.top=='(' and p==')')or(stack.top=='{' and p=='}'):
            print(stack.pop())
            p=p+1
        else:
            print('error')
    print(p)
