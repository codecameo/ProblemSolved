#include <stdio.h>
#include <string.h>
typedef long long ll;
ll dp[30010];
int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

void change()
{
  memset(dp,0,sizeof(dp));
  dp[0] = 1;
  for(int j=0;j<11;j++)
  {
    for(int i=coin[j];i<30000;i++)
    {
      dp[i] += dp[i-coin[j]];
    }
  }
  //for(int i=0;i<100;i++) cout<<i<<" "<<dp[i]<<endl;
}

int main()
{
  double tk,tk1;
  int n;
  change();
  while(scanf("%lf",&tk) != EOF)
  {
    tk1=100*tk;
    n=tk1;
    printf("%6.2lf%17llu\n",tk,dp[n]);
  }
  return 0;
}
