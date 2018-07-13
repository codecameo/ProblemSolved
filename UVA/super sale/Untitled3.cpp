#include <stdio.h>
#include <string.h>
#define inf_min -3453465;
int dp[10100],w[10000],p[10000],vi[10000],m;
int knapsack(int cap)
{
    printf("%dc\n",cap);
    int i,x;
    //if(cap<0)
    //return inf_min;
    if(cap==0)
    return 0;
    if(vi[cap]==1)
    return dp[cap];
    vi[cap]=1;
    //memset(dp,-1,sizeof(dp));
    for(i=0;i<m;i++){
        if(cap-w[i]>0)
    x=knapsack(cap-w[i])+p[i];
    if(x>dp[cap])
    dp[cap]=x;
    }


}

int main ()
{
    int kase,i,c,a;
    scanf("%d",&kase);
    while(kase--){
        memset(dp,-1,sizeof(dp));
     scanf("%d",&m);
     for(i=0;i<m;i++)
     scanf("%d %d",&p[i],&w[i]);
     scanf("%d",&c);
      a=knapsack(c);
      printf("%d\n",a);
    }


}
