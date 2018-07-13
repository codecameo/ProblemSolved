#include <stdio.h>
int main()
{
    long long int t,n,m,i,num;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        num=n/2;
        if(num>m)
        {
            for(i=1,num=0;i<=m;i++)
            {
                //if(i!=1)
                //printf(" ");
                printf("%lld ",num+=2);
            }
            puts("");
        }
        else
        puts("-1");
    }
}
