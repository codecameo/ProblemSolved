#include <stdio.h>
#include <string.h>
#define MOD 100000007
#define N 80000
int dp[N],n,tk;
int coin[109];
int solve()
{
    int i,j;
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=0;i<n;i++){
    for(j=coin[i];j<=tk;j++){
    dp[j]+=dp[j-coin[i]];
    dp[j]=dp[j]%MOD;
    }
    }
    return dp[tk];
}

int main()
{
    //freopen("data.in", "r", stdin);
    int t,i,kase=1;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&n,&tk);
    for(i=0;i<n;i++)
    scanf("%d",&coin[i]);
    printf("Case %d: %d\n",kase++,solve());
    }
    return 0;
}
