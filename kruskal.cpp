#include <bits/stdc++.h>
using namespace std;

void Edge(vector <pair<int, int> > matrix[], int x,
									int y, int k)
{
	matrix[k].push_back(make_pair(x, y));
}
struct pairs{
    int w,n;
};
bool compareInterval(pairs i1 ,pairs i2)
{
    return (i1.w < i2.w);
}
void unio(int hash[100][2],int x,int y,int siz)
{
    int change,fixed;
    if(hash[x][1]>hash[y][1])
    {
        change=hash[y][0];
        fixed=hash[x][0];
        x=hash[x][1];
        y=hash[y][1];
        for (int i = 0; i < siz; i++)
        {
            if(hash[i][0]==change)
            {
                hash[i][0]=fixed;
                hash[i][1]=x+hash[i][1];
            }
            else if(hash[i][0]==fixed)
                 hash[i][1]=hash[i][1]+y;
        }
    }
    else
    {
       change=hash[x][0];
        fixed=hash[y][0];
    x=hash[x][1];
    y=hash[y][1];
    for (int i = 0; i < siz; i++)
    {
        if(hash[i][0]==change)
        {
            hash[i][0]=fixed;
            hash[i][1]=y+hash[i][1];
        }
        else if(hash[i][0]==fixed)
             hash[i][1]=hash[i][1]+x;
    }
    }
}
int main()
{
	int v;
    printf("enter no of vertices:- ");
    scanf("%d",&v);
    vector<int> visited (v,0);
    pairs sort_w[v];
    int hash[100][2];
    for(int i=1;i<=v;i++){hash[i-1][0]=i-1;hash[i-1][1]=1;}
	vector<pair<int, int>> matrix[1000];
	int k=0;
    printf("format for input \nvertex v1 = '1',vertex v5 = '5'.... etc\n here '1' and '5' represent vertex v1 and v5\nexample input for edge and weight between v1 and v5-\n1 5 32'\n\n");
    while(true)
    {
        printf("press 1 to input data 0 to Exit--");
        int i=0;
        scanf("%d",&i);
        if(i!=0)
        {
        int x,y,w;
        printf("enter edge and weight>>>");
        scanf("%d %d %d",&x,&y,&w);
        Edge(matrix,x,y,k);
        sort_w[k]={w,k};
        k++;
        }
        else
            break;
    }
    vector<pair<int,int>>min_edge;
    sort(sort_w, sort_w+k, compareInterval);
    cout<<"Kruskal Minimum Spanning Tree";
    for(int i=0;i<k;i++)
    {
        if(hash[matrix[sort_w[i].n][0].first] [0]!=hash[(matrix[sort_w[i].n][0]).second] [0])
        {
            unio(hash,matrix[sort_w[i].n][0].first,matrix[sort_w[i].n][0].second,sizeof(hash)/sizeof(hash[0]));
            min_edge.push_back(make_pair(matrix[sort_w[i].n][0].first,matrix[sort_w[i].n][0].second));
            cout<<"\n("<<matrix[sort_w[i].n][0].first<<","<<matrix[sort_w[i].n][0].second<<") weight = "<<sort_w[i].w;
        }
    }
    return 0;
}
