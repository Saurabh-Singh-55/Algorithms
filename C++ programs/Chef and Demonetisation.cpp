// A Dynamic Programming based C++ program to find minimum of coins
// to make a given change V
#include<bits/stdc++.h>
using namespace std;
 int main()
{
     long long n;
    cin>>n;
     long long x ,y;
    for( long long j=0;j<n;j++)
    {
    cin>>x>>y;
     long long m=x;
     long long n=y;
     long long r=0;
    while(m!=0)
    {
        r=r+m/n;
        m=m%n;
        if(m%2==0)
            n=m;
        else if(m!=1)
            n=m-1;
        else
            n=1;

    }
    cout<<r<<endl;
}
	return 0;
}
