#include <stdio.h>
#include <string.h>
#define N 10001
long long int dp[N],n,tk;
long long int coin[22];
long long int solve()
{
    int i,j;
    if(dp[tk]!=0)
    return dp[tk];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<21;i++){
    for(j=coin[i];j<=tk;j++){
    dp[j]+=dp[j-coin[i]];
    dp[j]=dp[j];
    }
    }
    return dp[tk];
}

int main()
{
    //freopen("data.in", "r", stdin);
    int t,i,kase=1;
    for(i=1;i<=21;i++)
    coin[i-1]=i*i*i;
    while(scanf("%lld",&tk)!=EOF){
    printf("%lld\n",solve());
    }
    return 0;
}
