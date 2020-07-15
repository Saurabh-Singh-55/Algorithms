#include<cstdlib>
#include<cstdio>
#include<vector>
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
vector <int> final;
int counter=0;
void dfs(int n,int arr[][2],vector <int> state,vector<int> visit)
{
    if(final.size()!=2*n)
    if(state.size()!=n)
    {
        visit.resize(n+1,0);
        for(int i=0;i<state.size();i++)
            visit[state[i]]=1;
        state.push_back(1);
        for(int j=arr[state.size()-1][0];j<=arr[state.size()-1][1]&&counter!=1;j++)
        {
            if(visit[j]==0)
            {
            state[state.size()-1]=j;
            dfs(n,arr,state,visit);
            }
        }
    }
    else
    {
        for(int i=0;i<state.size();i++)
            final.push_back(state[i]);
    }
}
int main()
{
    int n,a,b;
    scanf("%d",&n);
    int arr[n][2];
    for(int i=0;i<n;i++)
    {
    scanf("%d %d",&a,&b);
    arr[i][0]=a;
    arr[i][1]=b;
    }
    vector<int> state;
    vector<int> visit(n+1,0);
    dfs(n,arr,state,visit);
    if(final.size()/n==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    for(int i=0;i<final.size();i++)
        if(i==n)
            printf("\n%d ",final[i]);
        else
            printf("%d ",final[i]);
}
