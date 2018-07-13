#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define inf_min -3453465;
using namespace std;
int dp[1010][1010],w[1010],p[1010],m;
int sack(int i,int cap)
{
    if(cap<0)
    return inf_min;
    if(i==m)
    return 0;
    if(cap==0)
    return 0;

    if(dp[i][cap]!=-1)
    return dp[i][cap];

    int ret1=0,ret2=0;
    ret1=p[i]+sack(i+1,cap-w[i]);
    ret2=sack(i+1,cap);
    dp[i][cap]=max(ret1,ret2);
    return dp[i][cap];
}



int main ()
{
    int kase,i,c,a,n,ans;
    scanf("%d",&kase);
    while(kase--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&m);

        for(i=0;i<m;i++)
            scanf("%d %d",&p[i],&w[i]);

        scanf("%d",&n);
        for(i=0,ans=0;i<n;i++)
        {

            scanf("%d",&c);
            a=sack(0,c);
            //printf("%d\n",a);
            ans+=a;
        }
        printf("%d\n",ans);
    }
return 0;
}
