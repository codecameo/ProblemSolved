#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using namespace std;
const int inf=3276754667;
long long int ans;
long long int d[5010],d_min[5010],n,mn;
struct ed
{
    long long int v,w;
};
vector <ed> edge[5010];

struct data
{
    long long int city,dist;
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
        int ucost=d[u.city];
        for(i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i].v;
            v.dist=edge[u.city][i].w;
            mn=v.dist+d[u.city];
            if(d[v.city]>mn)
            {
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
    long long int t,e,i,scr,kase=1,x,y,c,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&e);
        ans=inf;
       //reset();
        for (i=0;i<=n+1;i++)
        {
            /*for (j=0;j<n;j++)
            cost[i][j]=inf;
            cost[i][i]=0;*/
            d[i]=inf;
            d_min[i]=inf;
            edge[i].clear();
        }
        for(i=0;i<e;i++)
        {
            ed edg;
            scanf("%lld %lld %lld",&x,&y,&c);
            edg.v=y;
            edg.w=c;
            edge[x].pb(edg);
            edg.v=x;
            edge[y].pb(edg);
            //cost[x][y]=cost[y][x]=c;
            //min(cost[y][x],c);
            //printf("%d\n",cost[x][y]);
        }
        //par[1]=-1;
        dijkstra(1);
        //printf("%d %d\n",ans,d_min[n]);
        if(ans>d[n]+d_min[n]*2)
        ans=d[n]+d_min[n]*2;
        //printf("%d\n",ans);
        printf("Case %lld: %lld\n",kase++,ans);
    }
    return 0;
}
