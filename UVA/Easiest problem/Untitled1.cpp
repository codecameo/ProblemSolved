#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int a[3],i;
    int T,k;
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
        for(i=0;i<3;i++)
        scanf("%lld",&a[i]);
        sort(a,a+3);
     if(a[2]<(a[0]+a[1]))
     {
         if(a[0]==a[1] && a[1]==a[2])
         printf("Case %d: Equilateral\n",k);
         else if(a[0]!=a[1] && a[1]!=a[2] && a[2]!=a[0])
         printf("Case %d: Scalene\n",k);
         else
         printf("Case %d: Isosceles\n",k);
     }
     else
     printf("Case %d: Invalid\n",k);
    }

    return 0;
}
