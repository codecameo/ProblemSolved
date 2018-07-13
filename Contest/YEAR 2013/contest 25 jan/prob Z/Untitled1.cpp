#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[10000],dp[10000],n;
int f1(int pos){
if(pos>n-1) return 0;
if(pos==n-2 || pos==n-1) return a[pos];
if(dp[pos]) return dp[pos];
return dp[pos]+=max((a[pos]+f1(pos+2)),(a[pos]+f1(pos+3)));
}
int f2(int pos){
if(pos>n-2) return 0;
if(pos==n-2 || pos==n-3) return a[pos];
if(dp[pos]) return dp[pos];
return dp[pos]+=a[pos]+max(f2(pos+2),f2(pos+3));
}
int f3(int pos){
if(pos>n-3) return 0;
if(pos==n-4 || pos==n-3) return a[pos];
if(dp[pos]) return dp[pos];
return dp[pos]+=a[pos]+max(f3(pos+2),f3(pos+3));
}
int main()
{
int t,i,kase=1,x,y,z,mx;
scanf("%d",&t);
while(t--)
{
    memset(dp,0,sizeof(dp));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    x=f1(1);
    //printf("%d\n",x);
    memset(dp,0,sizeof(dp));
    y=f2(0);
    mx=max(x,y);
    memset(dp,0,sizeof(dp));
    z=f3(2)+a[n-1];
    //printf("%d\n",y);
    printf("Case %d: %d\n",kase++,max(z,mx));

}
return 0;
}
