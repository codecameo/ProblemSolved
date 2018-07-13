#include <iostream>
#include<cstdio>
#include<cstring>
#define N 1005
using namespace std;
int dp[N][N];
char s[N];
int DP(int i,int j)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i==j)
    return dp[i][j]=1;
    if(i>j)
    return dp[i][j]=0;
    if(s[i]==s[j])
    return dp[i][j]=2+DP(i+1,j-1);
    else
    return dp[i][j]=max(DP(i+1,j),DP(i,j-1));
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(s);
        int len=strlen(s);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",DP(0,len-1));
    }
    return 0;
}
