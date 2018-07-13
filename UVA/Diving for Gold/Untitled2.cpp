#include <stdio.h>
#include <string.h>
#include <algorithm>
#define inf_min -3453465;
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
    else return a.cost < b.cost;
}
data ar[100];
int DP(int i,int tk)
{
    int res1=0,res2=0;
    if(fd-tk<2000 && fd-tk+ar[i].cost>2000 && !flag){
    //printf("1st %df %dt %d(f-t) %dc %d\n",fd,tk,fd-tk,ar[i].cost,fd-tk+ar[i].cost);
    tk=tk+200;
    //fd+=200;
    flag=true;
    }
    //printf("%d %d\n",i,fd);
    if(i==n)
    return 0;
    if(tk<0)
    return inf_min;
    if(dp[i][tk]!=-1)
    return dp[i][tk];
    if(tk-ar[i].cost>=0)
    res1=ar[i].fav+DP(i+1,tk-ar[i].cost);
    res2=DP(i+1,tk);
    return dp[i][tk]=max(res1,res2);
}
int main()
{
    int i;
    while(scanf("%d %d",&fd,&n)==2)
    {
        flag=false;
        memset(dp,-1,sizeof(dp));
        flag=false;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&ar[i].cost,&ar[i].fav);
        }
        sort(ar,ar+n,compare);
        if(ar[0].cost>=2000){
        fd+=200;
        flag=true;
        }
        printf("%d\n",DP(0,fd));

    }
    return 0;
}
