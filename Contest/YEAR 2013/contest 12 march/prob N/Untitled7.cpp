#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf_min -3453465
using namespace std;
int dp[410][4010],n,fd;
bool flag;
//int cost[10],fv[10];
struct data {
    int cost, fav;
};
bool compare( data a, data b ) {
    if( a.cost == b.cost )
    return a.fav > b.fav;
    else
    return a.cost < b.cost;
}
data ar[110];
int DP()
{
    dp[0][0]=0;
    int i,j;
    for(i=1;i<n;i++)
    {
        flag=false;
        for(j=0;j<fd;j++)
        {
            if(i==j)
            continue;
            if(!flag)
            {
                if(j>2000)
                fd+=200;
                flag=true;
            }
            dp[i][j]=max(dp[i-1][j],(ar[i].fav+dp[i][j-ar[i].cost]));
        }
    }
    printf("%d\n",dp[n][fd]);
    return dp[n][fd];
}
int main()
{
    int i;
    while(scanf("%d %d",&fd,&n)!=EOF)
    {
        flag=false;
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].cost,&ar[i].fav);
        }
        sort(ar,ar+n,compare);
        if(ar[0].cost>=2000){
        fd+=200;
        flag=true;
        }
        printf("%d\n",DP());
        printf("%d\n",fd);

    }
    return 0;
}
