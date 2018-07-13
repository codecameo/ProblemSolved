#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define pb push_back
using namespace std;
const int inf=32767;
vector<int> edge[505];
int cost[501][501];
int d[501],visit[501];
struct data
{
    int city,dist;
    bool operator<(const data &p)const{
    return dist>p.dist;
    }
};
void dijkstra(int source)
{
    int i,mn;
    priority_queue <data> q;
    data u,v;
    u.city=source;
    u.dist=0;
    q.push(u);
    d[source]=0;
    while(!q.empty())
    {
        u=q.top();  q.pop();
        if(visit[u.city]) continue;
        visit[u.city]=1;
        int ucost=d[u.city];
        for(i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i];
            v.dist=cost[u.city][v.city];
            mn=max(v.dist,d[u.city]);
            if(d[v.city]>mn){
            d[v.city]=mn;
            q.push(v);
            }
        }
    }
}
int main()
{
    int t,n,e,i,scr,kase=1,x,y,c,j;
    scanf("%d",&t);
    //puts("");
    while(t--)
    {
        scanf("%d %d",&n,&e);
        for (int i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
                cost[i][j]=inf;
            cost[i][i]=0;
            d[i]=inf;

            visit[i]=0;
            edge[i].clear();
        }
        for(i=0;i<e;i++)
        {
            scanf("%d %d %d",&x,&y,&c);
            edge[x].pb(y);
            edge[y].pb(x);
            cost[y][x]=min(cost[y][x],c);
            cost[x][y]=min(cost[x][y],c);
            //cost[x][x]=cost[y][y]=0;
        }
        /*for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            printf("%d ",cost[i][j]);
            puts("");
        }*/
        scanf("%d",&scr);
        dijkstra(scr);
        printf("Case %d:\n",kase++);
        for(i=0;i<n;i++)
        {
            if(d[i]==inf)
            puts("Impossible");
            else
            printf("%d\n",d[i]);
        }
    }
    return 0;
}
