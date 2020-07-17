#include<iostream>
#include<string>
#include<queue>
#include<stdio.h> // for string class
using namespace std;


void strg(int n)
{


    for(int i =0; i<n;i++)
    {
        queue <char> q;
        int visit[]={1,0,0,0};
        string s;


        cin>>s;
        int l=s.length();
        for(int j=0;j<s.length();j++)
        {
            int r=s[j]-'0';
            visit[r]++;
            q.push(s[j]);
            int x;
            while((visit[1]>=1)&&(visit[2]>=1)&&(visit[3]>=1))
            {   if(l>q.size())
                    l=q.size();
                int y=q.front()-'0';
                if((visit[y]-1)==0)
                    break;
                visit[y]--;
                q.pop();

            }
        }
        if(visit[1]==0||visit[2]==0||visit[3]==0)
            cout<<0<<endl;
        else
            cout<<l<<endl;

    }

}





int main() {
    int n;
	scanf("%d",&n);
	strg(n);
	return 0;
}
