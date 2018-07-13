#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define pb push_back
#define mod 747474747
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
int v[6680][8],d,n;
struct data
{
    int u,v;
    long long int cost;
    bool operator <(const data &p)const{
        return cost<p.cost;
    }
};
priority_queue<data>q;
int par[6680];
void inititialize()
{
    int i;
    for(i=1;i<=n+1;i++) par[i]=i;
}
int find(int r)
{
    if(par[r]==r)  return r;
    return par[r]=find(par[r]);
}
long long int dist(int x,int y)
{
    int j;
    long long int ans;
    for(j=0,ans=0;j<d;j++)
    {
        ans+=(v[x][j]-v[y][j])*(v[x][j]-v[y][j]);
    }
    return ans;
}

int main()
{
    int t,i,j;
    long long int cos;
    int count,u,w;
    long long int s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&d);
        data g;
        mem(par,0);
        for(i=0;i<n;i++)
        {
            for(j=0;j<d;j++)    scanf("%d",&v[i][j]);
            for(j=0;j<i;j++)
            {
                cos=dist(i,j);
                g.u=i;
                g.v=j;
                g.cost=cos;
                q.push(g);
            }
        }
        inititialize();
        count=0;
        s=1;
        for(i=0;!q.empty();i++)
        {
            g=q.top();
            q.pop();
            u=find(g.u);
            w=find(g.v);
            if(u!=w)
            {
                par[u]=w;
                count++;
                s*=g.cost;
                s=s%mod;
                if(count==n-1) break;
            }
        }
        s=s%mod;
        printf("%lld\n",s);
    }
    return 0;
}
