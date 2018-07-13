#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 10010
using namespace std;
vector< int > G[MAX];
int low[MAX],vis[MAX],used[MAX],cut[MAX],dfstime,count,m,n;
void reset()
{
    int i;
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	memset(cut,0,sizeof(cut));
	for(i=0;i<=n+1;i++)
	G[i].clear();
	count=0;
	dfstime=0;
}
void get_input()
{
    scanf("%d %d",&n,&m);
    int i,a,b;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
void dfs(int u, int par = -1) {
    int i, v, child = 0;
    printf("u-> %d par-> %d\n",u,par);
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        printf("u-> %d v-> %d\n",u,v);
        if(v == par) continue;
        if(used[v]) low[u] = min(low[u], vis[v]);
        else {
            child++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= vis[u]) cut[u] = 1;
        }
    }
    if(par == -1) cut[u] = (child > 1);
}
int main()
{
	int t,kase=1,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		reset();
		//scanf("%d %d",&n,&m);
        get_input();
		dfs(1,-1);
		count=0;
		for(i=0;i<=n;i++)
         if(cut[i])
         {count++;
         printf("%d\n",i);
         }
         for(i=1;i<=n;i++)
             printf("(%d %d)\n",vis[i],low[i]);
        puts("");
        /*for(i=1;i<=n;i++)
             printf("%d ",low[i]);
        puts("");*/
		printf("Case %d: %d\n",kase++,count);
	}
}
