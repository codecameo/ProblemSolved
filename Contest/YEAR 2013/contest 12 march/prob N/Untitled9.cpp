#include <stdio.h>
#include <string.h>
#include <algorithm>
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
data ar[100];
int DP(int i,int tk,bool flag1)
{
    int res1=0,res2=0;
    if(fd-tk<=2000 && fd-tk+ar[i].cost>2000 && !flag1){
    //printf("1st %df %dt %d(f-t) %dc %d\n",fd,tk,fd-tk,ar[i].cost,fd-tk+ar[i].cost);
    tk=tk+200;
    //fd+=200;
    flag1=true;
    }
    //printf("%d %d\n",i,fd);
    if(i>n-1 || tk<0)
    return 0;
    if(dp[i][tk]!=-1)
    return dp[i][tk];
    if(tk-ar[i].cost>=0)
    res1=ar[i].fav+DP(i+1,tk-ar[i].cost,flag1);
    res2=DP(i+1,tk,flag1);
    return dp[i][tk]=max(res1,res2);
}
int main()
{
    int i;
    while(scanf("%d %d",&fd,&n)!=EOF)
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
        printf("%d\n",DP(0,fd,flag));

    }
    return 0;
}
