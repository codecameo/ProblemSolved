#include <stdio.h>
int main ()
{
   long long int i,j,num[3],k,sum=0,pro=1,n;
    while(scanf("%lld",&k)!=EOF)
    {
        while(k--)
        {
            scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
          {
            scanf("%lld",&num[j]);
          }
        pro=num[0]*num[2];
        sum+=pro;
        pro=1;
        }
         printf("%lld\n",sum);
        sum=0;
    }
        }

    return 0;
}
