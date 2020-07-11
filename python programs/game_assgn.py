import queue
def possible_States(state):
    l=[]
    x=[]
    i=state.index(0)
    if (i+1)<len(state) and state[i+1]==2:
        x=state[:]
        x[i]=2
        x[i+1]=0
        l.append(x)
    if (i-1)>=0 and state[i-1]==1:
        x=state[:]
        x[i]=1
        x[i-1]=0
        l.append(x)
    if (i+2)<len(state) and state[i+2]==2:
        x=state[:]
        x[i]=2
        x[i+2]=0
        l.append(x)
    if (i-2)>=0 and state[i-2]==1:
        x=state[:]
        x[i]=1
        x[i-2]=0
        l.append(x)
    return l
def bfs_shift(n):
    s = queue.Queue(maxsize=1000)
    start=[]
    goal=[]
    for i in range(0,2*n+1):
        if i<n:
            start.append(1)
            goal.append(2)
        if i==n:
            start.append(0)
            goal.append(0)
        if i>n:
            start.append(2)
            goal.append(1)
    visited_state=[start]
    data=[[start],0]
    s.put(data)
    k=0
    while not s.empty():
        current=s.get()
        k=k+1
        if current[0][-1]==goal:
            print(current[1])
            for i in current[0]:
                print(i)
        for next_state in possible_States(current[0][-1]):
            if next_state not in visited_state:
                visited_state.append(next_state)
                next_states=current[0][:]
                next_states.append(next_state)
                s.put((next_states,current[1]+1))
    print(k)
