#include <stdio.h>
#include <math.h>
int div(int num)
{
    if(num==0) return 0;
    else
    return num-1-(num-1)/3;
}
int main()
{
    long long int t,kase=1,m,n,ans=0,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        ans=div(m)-div(n-1);
        printf("Case %lld: %lld\n",kase++,ans);
    }
    return 0;
}
