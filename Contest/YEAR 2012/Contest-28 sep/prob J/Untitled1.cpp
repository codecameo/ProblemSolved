#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[1001][1001];
char s1[10000],s2[10000];

int solve()
{
  int l1,l2;
  memset(dp,0,sizeof(dp));
  l1 = strlen(s1);
  l2 = strlen(s2);
  for(int i=1; i <= l1; ++i ) dp[i][0] = 0;
  for(int i=1; i <= l2; ++i ) dp[0][i] = 0;
  for(int i=1;i<=l1;i++)
  {
    for(int j=1;j<=l2;j++)
    {
      if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
      else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
   // printf("%d ",dp[i][j]);
    }
    //printf("\n");
  }
  return dp[l1][l2];
}

int main()
{
  while(scanf("%s",s1)!=EOF)
  {
    scanf("%s",s2);
    printf("%d\n",solve());
  }
  return 0;
}
