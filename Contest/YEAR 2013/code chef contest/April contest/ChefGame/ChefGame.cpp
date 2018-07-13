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
    long long int cost;
    bool operator <(const data &p)const{
        return cost<p.cost;
    }
};
priority_queue<data>q;
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
int main()
{
    int t,i,j,count;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        data g;
        inititialize();
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
                //printf("%lld\n",cos);
                q.push(g);
            }
        }
     int count=0;
     long long int s=1;
    for(i=0;!q.empty();i++)
    {
        g=q.top();
        q.pop();
        int u=find(g.u);
        int v=find(g.v);
        if(u!=v)
        {
            par[u]=v;
            count++;
            s*=g.cost;
            s=s%mod;
            if(count==n-1) break;
        }
    }
    while(!q.empty())
    q.pop();
    printf("%lld\n",s%mod);
    }
    return 0;
}
