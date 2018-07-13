#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[1010][1010];
char st[100000];
int DP(int x,int y)
{
    if(dp[x][y]!=-1)
    return dp[x][y];
    if(x==y)
    return dp[x][y]=1;
    if(x>y)
    return dp[x][y]=0;
    if(st[x]==st[y])
    return dp[x][y]=2+DP(x+1,y-1);
    else
    return dp[x][y]=max(DP(x+1,y),DP(x,y-1));
}
int main(){
int tcase,l,kase=1;
scanf("%d",&tcase);
getchar();
while(tcase--){
gets(st);
l=strlen(st);
memset(dp,-1,sizeof(dp));
printf("Case %d: %d\n",kase++,l-DP(0,l-1));
}
return 0;
}

