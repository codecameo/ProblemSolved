#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int num[1000],j=-1,t,sm=0,tl,min1=7478;
int dp(int j,int s)
{
    int r,r1,r2;
    if(sm==tl)return 0;
    if(j>t)
    return 54435;
    r1=dp(j+1,s);
    r2=dp(j+1,((s-=num[j+1])-(sm+=num[j+1])));
    r=fabs(r1-r2);
    if(r<min1)
    min1=r;
    return min1;
}
int main ()
{
    int ans,m,i,sum;
    scanf("%d",&t);
    for(i=0,sum=0;i<t;i++)
    {
        scanf("%d",&num[i]);
        sum+=num[i];
    }
    tl=sum;
    ans=dp(-1,sum);
    printf("%d\n",ans);
    return 0;
}
