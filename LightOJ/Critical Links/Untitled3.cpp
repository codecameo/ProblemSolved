#include <stdio.h>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#define MAX 10010
using namespace std;
vector<int> G[MAX];
int low[MAX],vis[MAX],dfstime,color[MAX],count=0;
struct edges{
    int a,b;
    bool operator < ( const edges& p ) const
    {
        if(a==p.a)  return b < p.b;
        return a < p.a;
    }
};
vector<edges>Bridges;
edges edge;
void dfs(int u,int par) {
    int i, v;
    if(color[u]!=0)
    return;
    color[u]=1;
    vis[u]=low[u] =dfstime++;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if(v == par) continue;
        if(color[v]==1) low[u] = min(low[u],vis[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > vis[u])
            {
                int x=u,y=v;
                if(x>y)
                swap(x,y);
                edge.a=x;
                edge.b=y;
                Bridges.push_back(edge);
            }
        }
    }
    color[u]=2;
}
void reset()
{
    dfstime=1;
    for(int i=0;i<MAX;i++) G[i].clear();
    Bridges.clear();
    memset(color,0,sizeof(color));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
}
int main()
{
    int t,kase=1,i,j,k,n,node,x,num;
    //scanf("%d",&t);
    while( scanf("%d",&node)!=EOF)
    {
        reset();
        for(i=0;i<node;i++)
        {
            scanf("%d (%d)",&n,&num);
            for(j=0;j<num;j++)
            {
                scanf("%d",&x);
                G[n].push_back(x);
            }
        }
        for(k=0; k<node; k++)
            if(color[k]==0) dfs(k,-1);
        printf("%d critical links\n",Bridges.size());
        sort( Bridges.begin(),Bridges.end());
        for(i=0;i<Bridges.size();i++)
            printf("%d - %d\n",Bridges[i].a,Bridges[i].b);
        puts("");
}
    return 0;
}
