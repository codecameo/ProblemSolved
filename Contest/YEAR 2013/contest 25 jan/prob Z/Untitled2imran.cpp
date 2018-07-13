#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<list>
#define pi acos(-1.0)
#define inf (1<<29)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define ppb pop_back
#define sz(a) ((int)a.size())
#define eps 1e-9

#define rep(i,init,n) for(int i=init;i<n;i++)
#define rem(i,init,n) for(int i=init;i>n;i--)

#define sqr(x) ((x)*(x))

#define si(a) scanf("%d",&a)
#define sd(a) scanf("%lf",&a)
#define sc(a) scanf("%c",&a)
#define ss(a) scanf("%s",a)

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

int a[1010];
int dp[1011];
int n;
int f1(int pos)
{
    if(pos>n-1) return dp[pos];
    if(dp[pos]) return dp[pos];
    return dp[pos]=max(a[pos]+f1(pos+2),f1(pos+1));
}

int f2(int pos)
{
    if(pos>n-2) return dp[pos];
    if(dp[pos]) return dp[pos];
    return dp[pos]=max(a[pos]+f2(pos+2),f2(pos+1));
}

int main()
{
    int T,CASE=0;
    si(T);
    while(T--)
    {
        CLR(a);
        CLR(dp);
        //printf("Case %d: ",++CASE);
        scanf("%d",&n);
        rep(i,0,n)  scanf("%d",&a[i]);
        int a,b;
        a=f1(1);
        CLR(dp);
        b=f2(0);
        printf("Case %d: ",++CASE);
        printf("%d\n",max(a,b));
    }
}
