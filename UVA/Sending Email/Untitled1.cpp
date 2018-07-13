#include <stdio.h>
#include <queue>
#include <string.h>
#define pb push_back
#define MAXN 21004
#define INF 0x3f3f3f3f
#include <vector>
using namespace std;
vector<int> edge[MAXN],cost[MAXN];
int d[MAXN],visit[MAXN];
struct data {
    int city, dist;
    friend bool operator<(data a,data b)
    {   return a.dist>b.dist; }
};
int dijkstra(int source, int destination) {
    memset(d,INF,sizeof(d));
    memset(visit,0,sizeof(visit));
    priority_queue<data> q;
    data u, v;
    u.city = source;
    u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while(!q.empty()) {
        //printf("%d\n",d[ destination ]);
        u = q.top(); q.pop();
        int ucost = d[ u.city ];
        for(int i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i];
            //printf("%d\n",v.city);
            if(visit[v.city]==1)
            continue;
             v.dist = cost[u.city][i] + ucost;
             //printf("%d %d %d\n",cost[0][1],v.dist,d[v.city]);
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
//printf("%d\n",d[ destination -1]);
    return d[ destination ];
}

int main ()
{
  int T,u,v,w,s,t,ncase=0,n,m,k,i;
    //node p;
    //printf("frf\n");
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&s,&t);
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge[u].pb(v);
            cost[u].pb(w);
            edge[v].pb(u);
            cost[v].pb(w);
        }
        k=dijkstra(s,t);
        if(k==INF) printf("Case #%d: unreachable\n",++ncase);
        else printf("Case #%d: %d\n",++ncase,k);
        for(i=0;i<n;i++)
        {
            cost[i].clear();
            edge[i].clear();
        }
    }
    return 0;
}
