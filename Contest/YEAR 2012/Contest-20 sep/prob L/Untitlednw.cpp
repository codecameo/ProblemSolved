#include <stdio.h>
#include <iostream>
using namespace std;
//unsigned long long int lcm;
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main ()
{
    int tcase,n,i,m;
    unsigned long long int sum;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d",&n,&m);
        //for(i=1,sum=0;i<=n;i++)
        //{
            i=gcd(n,m);
            //sum+=lcm;
            printf("%d\n",i);
        //}
        //printf("%llu\n",sum);
    }
    return 0;
}
