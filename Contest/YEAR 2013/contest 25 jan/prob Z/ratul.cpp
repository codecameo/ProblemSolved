#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>

using namespace std;
int t,i,j,k,l,n,a[1000009],d[1000009],s,ans,cn,mn,c[1000009],p,q,f,g;
int dp(int x,int y)
{
    if(d[y]!=0)
    {
        return d[y];
    }
    if(y>=n)
    {
        return d[y]=0;
    }
    else if((x==0)&&(y>=n-1))
    {
        return d[y]=0;
    }
    else
    {
        return d[y]=a[y]+max(dp(x,y+2),dp(x,y+3));
    }
}
int main()
{
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        ans=0;
        memset(d,0,sizeof(d));
        mn=dp(0,0);
        memset(d,0,sizeof(d));
        cn=dp(1,1);
        ans=max(mn,cn);
        memset(d,0,sizeof(d));
        s=dp(2,2);
        ans=max(ans,s);
        printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
