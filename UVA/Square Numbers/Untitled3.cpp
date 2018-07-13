#include <stdio.h>
#include <math.h>
int main ()
{
    long long int n,m,i,c,count;
    while(scanf("%lld %lld",&m,&n)!=EOF)
    {
        if(m==0 && n==0)break;
        for(i=m,count=0;i<=n;i++)
        {
            c=sqrt(i);
            c=c*c;
            if(c==i)
            count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
