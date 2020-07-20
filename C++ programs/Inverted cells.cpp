#include <iostream>
#include<stdio.h>
#include<string>
#include<list>
#define NIL -1

using namespace std;
class Graph
{
	int V;
	list<int> *adj;
	void APUtil(int v, bool visited[], int disc[], int low[],
				int parent[], bool ap[]);
    bool DFSUtil(int v, bool visited[]);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void AP(int *a[],int n,int m);
	bool DFS(int v);
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}
bool Graph::DFSUtil(int v, bool visited[])
{
	// Mark the current node as visited and
	// print it
	visited[v] = true;
	if (v==V-1)
        {
            return true;
        }

	// Recur for all the vertices adjacent
	// to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			if(DFSUtil(*i, visited))
			    return true;
    return false;
}

bool Graph::DFS(int v)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	return DFSUtil(v, visited);
}
void Graph::APUtil(int u, bool visited[], int disc[],
									int low[], int parent[], bool ap[])
{
	static int time = 0;

	// Count of children in DFS Tree
	int children = 0;

	// Mark the current node as visited
	visited[u] = true;

	// Initialize discovery time and low value
	disc[u] = low[u] = ++time;

	// Go through all vertices aadjacent to this
	list<int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		int v = *i; // v is current adjacent of u

		// If v is not visited yet, then make it a child of u
		// in DFS tree and recur for it
		if (!visited[v])
		{
			children++;
			parent[v] = u;
			APUtil(v, visited, disc, low, parent, ap);

			// Check if the subtree rooted with v has a connection to
			// one of the ancestors of u
			low[u] = min(low[u], low[v]);

			// u is an articulation point in following cases

			// (1) u is root of DFS tree and has two or more chilren.
			if (parent[u] == NIL && children > 1)
			ap[u] = true;

			// (2) If u is not root and low value of one of its child is more
			// than discovery value of u.
			if (parent[u] != NIL && low[v] >= disc[u])
			ap[u] = true;
		}

		// Update low value of u for parent function calls.
		else if (v != parent[u])
			low[u] = min(low[u], disc[v]);
	}
}

// The function to do DFS traversal. It uses recursive function APUtil()
void Graph::AP(int *a[],int n,int m)
{

	bool *visited = new bool[V];
	int *disc = new int[V];
	int *low = new int[V];
	int *parent = new int[V];
	bool *ap = new bool[V]; // To store articulation points

	// Initialize parent and visited, and ap(articulation point) arrays
	for (int i = 0; i < V; i++)
	{
		parent[i] = NIL;
		visited[i] = false;
		ap[i] = false;
	}

	// Call the recursive helper function to find articulation points
	// in DFS tree rooted with vertex 'i'
	for (int i = 0; i < V; i++)
		if (visited[i] == false)
			APUtil(i, visited, disc, low, parent, ap);
    int cnt=0;
    for (int i = 0; i < V; i++)
		if (ap[i] == true)
		cnt=1;
    if(cnt)
    int x=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(ap[a[i][j]]==true)
                cout<<"0 ";
            else if((i==0&&j==0)||(i==n-1&&j==m-1))
                cout<<"0 ";
            else
                cout<<"1 ";
        }
        cout<<endl;
    }

}
int  nishantlove(int *arr[],int n,int m)
{
    int *a[n];
    for (int i=0; i<n; i++)
         a[i] = (int *)malloc(m * sizeof(int));
    int x=0;
    int count=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            if(arr[i][j]!=1&&(!(i==n-1&&j==m-1)))
            {
            if(i!=n-1)
            {
                if(j==m-1)
                {
                if(arr[i+1][j]==1)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
                }
                else if(arr[i+1][j]==1&&arr[i][j+1]==1)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;

            }
            else
            {
                if(arr[i][j+1]==1)
                    arr[i][j]=1;
            }
            if(j!=m-1)
            {
                if(i==n-1)
                {
                    if(arr[i][j+1]==1)
                        arr[i][j]=1;
                    else
                        arr[i][j]=0;
                }
                else if(arr[i+1][j]==1&&arr[i][j+1]==1)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
            }
            else
            {
                if(arr[i+1][j]==1)
                    arr[i][j]=1;
            }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                a[i][j]=count++;
                x++;
            }
        }
    }

    Graph g1(x);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]==0)
            {
                if(i!=n-1)
                {
                    if(j==m-1)
                        if(arr[i+1][j]==0)
                            g1.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i+1][j]==0)
                            g1.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i][j+1]==0)
                            g1.addEdge(a[i][j],a[i][j+1]);
                }
                else if(j!=m-1)
                {
                    if(i==n-1)
                        if(arr[i][j+1]==0)
                            g1.addEdge(a[i][j],a[i][j+1]);
                    if(arr[i+1][j]==0)
                            g1.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i][j+1]==0)
                            g1.addEdge(a[i][j],a[i][j+1]);
                }
            }
        }
    }
	g1.AP(a,n,m);


}

int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    int *a[n];
    for (int i=0; i<n; i++)
         a[i] = (int *)malloc(m * sizeof(int));
    int *arr[n];
    for (int i=0; i<n; i++)
         arr[i] = (int *)malloc(m * sizeof(int));
    int *arr2[n];
    for (int i=0; i<n; i++)
         arr2[i] = (int *)malloc(m * sizeof(int));
    string f;
    char k;
    int p=0;
    int count=0;
	for(int i=0;i<n;i++)
    {
        cin>>f;
        for(int j=0;j<m;j++)
        {
            k=f[j];
        if(k=='#'){
            arr[i][j]=1;
            arr2[i][j]=1;}
        else if(i!=0)
        {
            arr2[i][j]=0;
            p++;
            a[i][j]=count++;
            if(j==0)
            {
            if(arr[i-1][j]==1)
                arr[i][j]=1;
            else
                arr[i][j]=0;
            }
            else if(arr[i-1][j]==1&&arr[i][j-1]==1)
                arr[i][j]=1;
            else
                arr[i][j]=0;

        }
        else if(j!=0)
        {
            arr2[i][j]=0;
            p++;
            a[i][j]=count++;
            if(i==0)
            {
                if(arr[i][j-1]==1)
                    arr[i][j]=1;
                else
                    arr[i][j]=0;
            }
            else if(arr[i-1][j]==1&&arr[i][j-1]==1)
                arr[i][j]=1;
            else
                arr[i][j]=0;
        }
        else{
            p++;
            arr2[i][j]=0;
            arr[i][j]=0;
            a[i][j]=count++;
            }
        }
    }

    //cout<<"g2"<<p<<endl;

    Graph g2(p);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr2[i][j]==0)
            {
                if(i!=n-1)
                {
                    if(j==m-1)
                        if(arr[i+1][j]==0)
                            g2.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i+1][j]==0)
                            g2.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i][j+1]==0)
                            g2.addEdge(a[i][j],a[i][j+1]);
                }
                else if(j!=m-1)
                {
                    if(i==n-1)
                        if(arr[i][j+1]==0)
                            g2.addEdge(a[i][j],a[i][j+1]);
                    if(arr[i+1][j]==0)
                            g2.addEdge(a[i][j],a[i+1][j]);
                    if(arr[i][j+1]==0)
                            g2.addEdge(a[i][j],a[i][j+1]);
                }
            }
        }
    }
    //cout<<"check"<<endl;
    if(g2.DFS(0))
    {
        //cout<<"one"<<endl;
        nishantlove(arr,n,m);
    }
    else
    {
        //cout<<"two"<<endl;
        for(int i=0;i<n;i++)
        {   cout<<endl;
            for(int j=0;j<m;j++)
            {

                cout<<arr2[i][j]<<" ";
            }
        }
    }
	return 0;
}
