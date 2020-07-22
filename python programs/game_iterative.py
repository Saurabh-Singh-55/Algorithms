def game_itterative(n):
    state=[]
    for i in range(0,2*n+1):
        if i<n:
            state.append(1)
        if i==n:
            state.append(0)
        if i>n:
            state.append(2)
    print(state)
    space=n
    moves=0
    i=-1
    k=-1
    counter=0
    while counter!=3:
        if counter==0:
            k=k+1
            i=i*-1
            for j in range(0,k):
                state[space]=state[space+(2*i)]
                state[space+(2*i)]=0
                space=space+(2*i)
                moves=moves+1
                print(state)
            if (space + i)<=2*n and (space + i)>=0:
                state[space]=state[space+i]
                state[space+i]=0
                space=space+i
                moves=moves+1
                print(state)
            else:
                counter =1
        else :
            k=k-1
            i=i*-1
            state[space]=state[space+i]
            state[space+i]=0
            space=space+i
            moves=moves+1
            print(state)
            if k==0:
                counter=3
                break
            for j in range(0,k):
                state[space]=state[space+2*i]
                state[space+2*i]=0
                space=space+2*i
                moves=moves+1
                print(state)
    print("moves -  ",moves)
            
