#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF -(1<<30)
#define pb push_back
#define mod 747474747
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
long long int dis[6670];
long long int G[6670][6670],d,n,v[6670][6];
bool vis[6670];
void reset()
{
    int i,j;
    for(i=0;i<6670;i++)
    {
        dis[i]=0;
        vis[i]=0;
    }
    for(i=0;i<6670;i++)
        for(j=0;j<6670;j++)
            G[i][j]=0;
    for(i=0;i<6670;i++)
        for(j=0;j<6;j++)
            v[i][j]=0;
}
long long int dist(int x,int y)
{
    int j;
    long long int ans=0;
    for(j=0;j<d;j++)
    {
        ans += (v[x][j]-v[y][j])*(v[x][j]-v[y][j]);
        //ans = ans % mod;
    }
    return ans;
}
void prim(int x)
{
	long long int i,j,k,max;
	long long int t=1;
	vis[0]=1;
	max=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max<G[x][j]&&!vis[j])
			{
				max=G[x][j];
				k=j;
			}
		}
		vis[k]=1;
		if(max==0)    max=1;
		if(max!=0)
		t*=max;
		t=t%mod;
		for(j=0;j<n;j++)
		{
			if(dis[j]<G[k][j]&&!vis[j])
			{
				dis[j]=G[k][j];
			}
		}
	}
	t = t%mod;
	printf("%lld\n",t);
}
int main()
{
    long long int t,i,j,cos;
    scanf("%lld",&t);
    while(t--)
    {
        reset();
        scanf("%lld %lld",&n,&d);
        for(i=0;i<n;i++)
        {
            for(j=0;j<d;j++)
            {
                scanf("%lld",&v[i][j]);
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cos=dist(i,j);
                G[i][j]=cos;
                G[j][i]=cos;
            }
        }
        prim(0);
    }
    return 0;
}
