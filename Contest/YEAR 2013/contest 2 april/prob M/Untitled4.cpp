#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int a[20][20],n;
long long int dp[100000][5][5];
bool check(int mask,int k)
{
    return mask&(1<<k);
}
int set1(int mask,int k)
{
    return mask|(1<<k);
}
long long int f(int i,int mask,int flag1,int flag2)
{
    if(i==n)
    {
        if(flag1 || flag2)  {printf("%dm\n",mask);
        return 1;}
        return 0;
    }
    if(dp[mask][flag1][flag2]!=-1)  return dp[mask][flag1][flag2];
    long long int ret=0,j;
    for(j=0;j<n;j++)
    {
        printf("i=%d j=%d ",i,j);
        printf("mask=%d flag1=%d flag2=%d\n",mask,flag1,flag2);
        if(check(mask,j))
        continue;
        puts("IN");
        if(a[i][j]==0)
            ret+=f(i+1,set1(mask,j),0,flag2);
        else if(a[i][j]==1)
            ret+=f(i+1,set1(mask,j),flag1,flag2);
        else ret+=f(i+1,set1(mask,j),flag1,1);
    }
    return dp[mask][flag1][flag2]=ret;
}

int main()
{
    int T,CASE=0;
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: ",++CASE);
        int a=1;
        printf("%lld\n",f(0,0,a,0));
    }
}
