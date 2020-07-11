#include <iostream>
#include<stdio.h>
using namespace std;
int  maxmin(long long int n)
{
    int r,x=n%10,y=n%10;
    while(n!=0)
    {
    r=n%10;
    if(x<r)
        x=r;
    if(y>r)
        y=r;
    n/=10;
    }
    return x*y;

}
void seq(int n)
{
    long long int a;
    long long int k;

    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld", &a,&k);
        for(int j=1;j<=k-1;j++)
        {
            if(maxmin(a)==0)
            break;
            a=a+maxmin(a);
        }
        cout<<a<<endl;
    }

}
int main() {
    int n;
	scanf("%d",&n);
	seq(n);
	return 0;
}
