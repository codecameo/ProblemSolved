#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define INF 0
#define pb push_back
#define mod 747474747
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
long long int G[6670][6670],dis[6670];
int v[6670][6];
int d,n;
bool vis[6670];
void reset()
{
    mem(vis,0);
   // mem(G,0);
    mem(v,0);
    mem(dis,0);
}
long long int dist(int x,int y)
{
    int j;
    long long int ans,a,b;
    for(j=0,ans=0;j<d;j++)
    {
        a=v[x][j];
        b=v[y][j];
        ans+=(a-b)*(a-b);
    }
    return ans;
}
int prim()
{
	int i,j,k;
	long long int t=1;
	vis[0]=1;
    k=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(vis[j]==0)
			{
                if(dis[j]<G[k][j])
                {
                    dis[j]=G[k][j];
                }
			}
		}

		long long int max=0;
		for(j=0;j<n;j++)
		{
			if(vis[j]==0)
			{
                if(max<dis[j])
                {
                    max=dis[j];
                    k=j;
                }
			}
		}
		vis[k]=1;
		if(max==0)    max=1;
		//cout<<max<<endl;
        t = ((t%mod)*(max%mod))%mod;
	}
	return t%mod;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        reset();
        scanf("%d %d",&n,&d);
        for(i=0;i<n;i++)
        {
            for(j=0;j<d;j++)
            {
                scanf("%d",&v[i][j]);
            }
            for(j=0;j<i;j++)
            {
                G[i][j]=G[j][i]=dist(i,j);
                //printf("%lld\n",G[i][j]);
            }
        }
        printf("%d\n",prim());
    }
    return 0;
}
