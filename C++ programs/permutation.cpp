#include<iostream>
#include <bits/stdc++.h>
using namespace std;


char* pp(char ch[])
{
    char str2[1000],o[1];
    int l= sizeof(ch),k=-1;
    char str[l-1];
    cout<<ch[0]<<ch[1]<<ch[2]<<ch[3]<<" ";
    if(l!=1)
    for (int i = 0;i<l;i++)
    {k=-1;
        for(int j=0;j<l;j++)
            if(i!=j)
            {
                str[++k]=ch[j];
            }
            o[0]=ch[i];
         strcpy(str2,strcat(o,pp(str)));
        cout<<str2<<endl;
    }
    else
        return ch;
}
int main()
{
    char c[4]={'a','b','c','d'};
    char *p=pp(c);
}
