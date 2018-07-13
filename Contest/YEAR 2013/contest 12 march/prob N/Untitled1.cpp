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
int DP(int i,int tk,bool flag1)
{
    //flag=false;
    printf("1st %d %d %d %d\n",i,tk,fd,flag1);
    int res1=0,res2=0;
    //printf("%d\n",flag);
    if(fd-tk<=2000 && fd-tk+ar[i].cost>2000 && !flag1){
    tk=tk+200;
    fd+=200;
    //printf("%d %d\n",tk,fd);
    flag1=true;
    }
   // printf("%d\n",fd);
    if(i>n-1 || tk<0)
    return 0;
    //if(tk<0)
    //return inf_min;
    if(dp[i][tk]!=-1)
    return dp[i][tk];
    if(tk-ar[i].cost>=0)
    res1=ar[i].fav+DP(i+1,tk-ar[i].cost,flag1);
    printf("res1: %d\n",res1);
    res2=DP(i+1,tk,flag1);
    printf("res2: %d\n",res2);
    return dp[i][tk]=max(res1,res2);
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
        printf("%d %d\n%d %d\n",ar[0].fav,ar[0].cost,ar[1].fav,ar[1].cost);
        if(ar[0].cost>=2000){
        fd+=200;
        flag=true;
        puts("fdj");
        }
        printf("%d\n",DP(0,fd,flag));
        //printf("%d\n",fd);

    }
    return 0;
}
