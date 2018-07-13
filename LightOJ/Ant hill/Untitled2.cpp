//Articulation Point

#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10010
int n,m;
vector< int > G[MAX];
int low[MAX], vis[MAX], used[MAX], cut[MAX], dfstime;
void reset()
{
    int i;
    memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	memset(cut,0,sizeof(cut));
	for(i=0;i<=MAX;i++)
	G[i].clear();
//	count=0;
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
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
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
    int T,CASE=0,cnt,i;
    scanf("%d",&T);
    while(T--)
    {
        cnt=0;
        reset();
        get_input();
        dfs(1,-1);
        for(i=0;i<=n;i++)
        if(cut[i])
        cnt++;
        //if()
        printf("Case %d: %d\n",++CASE,cnt);
    }
}
