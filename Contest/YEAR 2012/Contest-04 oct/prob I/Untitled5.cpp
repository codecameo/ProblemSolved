#include <stdio.h>
#define N 102
int dp[N][N];
int DP(int n,int k)
{
    int i,res;
    if(n<0||k<0)
        return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    else
    {
        res=0;
        for(i=0;i<=n;i++){
            res+=(DP(n-i,k-1)%1000000);
            printf("%d %d %d\n",res,n-i,k-1);
            }
        return dp[n][k]=res%1000000;
    }
}
int main()
{
    int x,y,ans,i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            dp[i][j]=-1;
    dp[0][0]=1;
    while(scanf("%d %d",&x,&y)&& x && y){
    ans=DP(x,y);
        printf("%d\n",ans);}
    return 0;
}
