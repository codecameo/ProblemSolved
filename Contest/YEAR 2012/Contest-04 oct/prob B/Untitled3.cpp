#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int num[1000],dp[1000][1000],t,j=-1;
int DP(int s)
{
    int j,i;
    dp[0][0]=0;
    for(i=1;i<=s/2;i++)
    dp[i][0]=1;
    for(i=1;i<=s;i++)
    dp[0][i]=1;
    for(i=1;i<=s/2;i++)
    {
        for(j=1;j<=s;j++)
        {
            dp[i][j]=(dp[i][j-1] or dp[i-num[j]][j-1]);
            printf("%d ",dp[i][j]);
        }
        printf("\n");
    }
    return dp[s/2][s];
}
int main ()
{
    int min,m,sum,s,i,sm;
    scanf("%d",&t);
    for(i=0,sum=0;i<t;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    printf("%d\n",DP(sum));
    return 0;
}
