#include <stdio.h>
#include <string.h>
long long int dp[100000][5][5];
int n,pr[20][20];
int set(int mask,int k)
{
    return (mask | 1<<k);
}
int check(int mask,int k)
{
    return (mask & 1<<k);
}
long long int DP(int i,int mask,int flag1,int flag2)
{
    if(i==n)
    {
        if(flag1 || flag2)  return 1;
        return 0;
    }
    if(dp[mask][flag1][flag2]!=-1)  return dp[mask][flag1][flag2];
    long long int ret=0,j;
    for(j=0;j<n;j++)
    {
        if(check(mask,j))   continue;

        if(pr[i][j]==0)
            ret+=DP(i+1,set(mask,j),0,flag2);
        else if(pr[i][j]==1)
            ret+=DP(i+1,set(mask,j),flag1,flag2);
        else ret+=DP(i+1,set(mask,j),flag1,1);
    }
    return dp[mask][flag1][flag2]=ret;
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
            scanf("%d",&pr[i][j]);
        printf("Case %d: %lld\n",kase++,DP(0,0,1,0));
    }
}
