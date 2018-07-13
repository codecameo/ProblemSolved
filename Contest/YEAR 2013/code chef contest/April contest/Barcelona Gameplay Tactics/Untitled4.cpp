#include <stdio.h>
#define mod 1000000007
int main()
{
    int t,n,k,loop,i;
    long long int a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        if(n==2)
        {
            printf("%d\n",k);
            continue;
        }
        loop=n-3;
        a=k-1;
        for(i=0;i<loop;i++)
        {
            if(i%2==0)
            a=((a*k)%mod)+1;
            else
            a=((a*k)%mod)-1;
        }
        a=a*k;
        printf("%lld\n",a%mod);
    }
}
