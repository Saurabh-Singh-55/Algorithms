import queue
def possible_States(graph,state):
    l=[]
    x=graph[state[0]][state[1]][0]
    y=graph[state[0]][state[1]][1]
    i=0
    while x-i!=0:
        if (state[0]+x)<=graph[-1][-1][0]:
            l.append((state[0]+x,state[1]))
        i=i+1
    i=0
    while y-i!=0:
        if (state[1]+y)<=graph[-1][-1][1]:
            l.append((state[0],state[1]+y))
        i=i+1
    return l
def bfs_frog(graph):
    s = queue.Queue(maxsize=1000) 
    start=(0,0)
    visited_state=[start]
    data=[start,0]
    s.put(data)
    while not s.empty():
        current=s.get()
        if current[0]==graph[-1][-1]:
            print(current[1])
            return []
        for next_state in possible_States(graph,current[0]):
            if next_state not in visited_state:
                visited_state.append(next_state)
                s.put((next_state,current[1]+1))
    print("Not possible")
def frog_main():
    graph=[]
    col=[]
    n, m = map(int,input().split())
    for i in range (0,n):
        for j in range(0,m):
            if not (i==n-1 and j==m-1):
                x,y = map(int,input().split())
                col.append((x,y))
            else:
                col.append((i,j))
        graph.append(col)
        col=[]
    bfs_frog(graph)        
