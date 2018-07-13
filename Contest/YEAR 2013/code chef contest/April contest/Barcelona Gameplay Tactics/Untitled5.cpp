#include <stdio.h>
#define mod 1000000007
int n,k;
long long int ans,pl[16];
void res(int player,int pass)
{
    //printf("%d %d\n",player,pass);
    int i;
    if(pass==n)
    return;
    if(pass==n-1 && player==pl[0])
    return;
    else if(pass==n-1 && player!=pl[0]){
    ans++;
    ans=ans%mod;
    //printf("ans-> %d\n",ans);
    return;
    }
    for(i=0;i<=k;i++)
    {
        if(i==player)
        continue;
        res(i,pass+1);
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<=k;i++)
        {
            pl[i]=i;
        }
         res(0,0);
        printf("%lld\n",ans);
        ans=0;
    }
}
