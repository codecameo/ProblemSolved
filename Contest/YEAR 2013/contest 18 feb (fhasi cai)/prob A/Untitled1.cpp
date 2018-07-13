#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int ar[101][101],dp[101][101],n,s;
int DP(int x,int y,int z)
{
    int l,Max;
    //printf("%d %d %d %d\n",x,y,z,ar[x][y]);
    if(x<0 || x>n-1 || y<0 || y>n-1 || ar[x][y]<=z){
        //printf("fh\n");
    return 0;
    }
    //printf("fh\n");
    if(dp[x][y]!=-1)
    return dp[x][y];
    for(l=1,Max=-1;l<=s;l++)
    {
        Max = max (Max, DP(x+l,y, ar[x][y])+ar[x][y]);
        Max = max (Max, DP(x-l,y, ar[x][y])+ar[x][y]);
        Max = max (Max, DP(x,y+l, ar[x][y])+ar[x][y]);
        Max = max (Max, DP(x,y-l, ar[x][y])+ar[x][y]);
        //return dp[x][y]=Max;
    }
    return dp[x][y]=Max;

}
int main(){
int t,i,j;
scanf("%d",&t);
//printf("\n");
while(t--)
{
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&s);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d",&ar[i][j]);
    printf("%d\n",DP(0,0,-1));
    if(t)
    printf("\n");
}
return 0;
}
