#include <iostream>
#include<stdio.h>
using namespace std;

void alarm(int n)
{
    long long int a,b,c,d;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld %lld", &a,&b,&c, &d);
        long long int x=a-b;
        long long int s=c-d;
        long long int z=b;
        if(a<=b)
            cout<<b<<endl;
        else if(d>=c)
            cout<<-1<<endl;
        else
          {
              long long int div=0;
                if(x%s==0)
                    div=x/s;
                else
                    div=x/s+1;
                z=z+c*div;

            cout<<z<<endl;
          }
    }

}
int main() {
    int n;
	scanf("%d",&n);
	alarm(n);
	return 0;
}
