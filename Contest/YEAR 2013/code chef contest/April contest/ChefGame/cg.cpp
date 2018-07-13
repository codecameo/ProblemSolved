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
int v[6670][6],d,n;
struct data
{
    int u, v;
    double cost;
    bool operator <(const data &p)const{
        return cost>p.cost;
    }
};
vector<data>q;
int par[6670];
void inititialize()
{
    for(int i=1;i<=n+1;i++)
    par[i]=i;
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
long long int mst()
{
    sort(q.begin(),q.end());
    inititialize();
    int count=0;
    long long int s=1;
    for(int i=0;i<(int)q.size();i++)
    {
        int u=find(q[i].u);
        int v=find(q[i].v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s*=q[i].cost;
            s=s%mod;
            if(count==n-1) break;
        }
    }
    return s%mod;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&d);
        data g;
        mem(par,0);
        q.clear();
        for(i=0;i<n;i++)
        {
            for(j=0;j<d;j++)
            {
                scanf("%d",&v[i][j]);
            }
            for(j=0;j<i;j++)
            {
                long long int cos=dist(i,j);
                g.u=i;
                g.v=j;
                g.cost=cos;
                q.pb(g);
            }
        }
    printf("%lld\n",mst());
    }
    return 0;
}
