#include <stdio.h>
#include <string.h>
long long int dp[35000][5][5];
int n,pr[20][20];
int set(int mask,int k)
{
    return (mask | 1<<k);
}
int check(int mask,int k)
{
    return (mask & 1<<k);
}
long long int DP(int i,int mask,bool flag1,bool flag2)
{
    long long int res,j;
    if(i==n)
    {
        if(flag1 || flag2)
        return 1;
        else
        return 0;
    }
    if(dp[mask][flag1][flag2]!=-1)
    return dp[mask][flag1][flag2];
    res=0;
    for(j=0;j<n;j++)
    {
        if(check(mask,j))
        continue;
        if(pr[i][j]==0)
        res+=DP(i+1,set(mask,j),0,flag2);
        else if(pr[i][j]==1)
        res+=DP(i+1,set(mask,j),flag1,flag2);
        else
        res+=DP(i+1,set(mask,j),flag1,1);
    }
    return dp[mask][flag1][flag2]=res;
}
int main()
{
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&pr[i][j]);
        }
        printf("Case %d: %lld\n",kase++,DP(0,0,1,0));
    }
}
