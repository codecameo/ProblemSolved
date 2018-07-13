#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using namespace std;
const int inf=32767;
vector<int> edge[5001];
int cost[5001][5001],ans;
int d[5001],d_min[5001],n,mn;
void reset()
{
    for(int i=0;i<=5001;i++)
    {
        d[i]=inf;
        d_min[i]=inf;
        ans=inf;
    }
}
struct data
{
    int city,dist;
    bool operator<(const data &p)const{
    return dist<p.dist;
    }
};
void dijkstra(int source)
{
    int i;
    priority_queue <data> q;
    data u,v;
    u.city=source;
    u.dist=0;
    q.push(u);
    d[source]=0;
    while(!q.empty())
    {
        u=q.top();  q.pop();
        //if(visit[u.city]) continue;
        //visit[u.city]=1;
        int ucost=d[u.city];
        for(i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i];
            v.dist=cost[u.city][v.city];
            mn=v.dist+d[u.city];
            if(d[v.city]>mn)
            {
                //printf("%d %d %d\n",ans,d[v.city],mn);
                if(v.city==n)
                {
                   if(d[v.city]<ans)
                   ans=d[v.city];
                }
                d[v.city]=mn;
                mn=min(d_min[u.city],v.dist);
                if(d_min[v.city]>mn)
                    d_min[v.city]=mn;
                q.push(v);
            }
            else
            {
                if(v.city==n)
                {
                   if(mn<ans)
                   ans=mn;
                }
            }
        }
    }
}
int main()
{
    int t,e,i,scr,kase=1,x,y,c,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&e);
        ans=inf;
       //reset();
        for (int i=0;i<=n+1;i++)
        {
            for (j=0;j<n;j++)
            cost[i][j]=inf;
            cost[i][i]=0;
            d[i]=inf;
            d_min[i]=inf;
            edge[i].clear();
        }
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            edge[x].pb(y);
            edge[y].pb(x);
            cost[x][y]=cost[y][x]=c;
            //min(cost[y][x],c);
            //printf("%d\n",cost[x][y]);
        }
        //par[1]=-1;
        dijkstra(1);
        //printf("%d %d\n",ans,d_min[n]);
        if(ans>d[n]+d_min[n]*2)
        ans=d[n]+d_min[n]*2;
        //printf("%d\n",ans);
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}
