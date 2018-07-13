#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#define MAX 10100
using namespace std;
vector<int>G[MAX];
//vector< pair< int, int > > Bridges;
int low[MAX],vis[MAX],used[MAX],degree[MAX],dfstime;
bool flag=0;
int count,m,n,count1;
void reset()
{
    int i;
    flag=0;
	for(i=0;i<=MAX;i++)
	G[i].clear();
	dfstime=0;
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	memset(used,0,sizeof(used));
	//memset(cut,0,sizeof(cut));
	count=0;
	count1=0;
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
void dfs(int u, int par) {
    int i, v;
    used[u] = 1;
    vis[u] = low[u] = ++dfstime;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if(v == par) continue;
        if(used[v]) low[u] = min(low[u], vis[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > vis[u]) {
            //Bridges.push_back(make_pair(u,v));
            printf("%du %dv\n",u,v);
            count1++;
            }
        }
    }
}

int main()
{
	int t,kase=1,i,a,b,x,j;
	scanf("%d",&t);
	while(t--)
	{
		reset();
		get_input();
        /*for(i=0,flag=0;i<n;i++)
		{
		    if(G[i].size()==1)
		    {
		        if(flag==0)
		        {
		            x=i;
		            flag=1;
                }
		        else
		        flag=0;
		        if(flag==0)
		        {
		            G[i].push_back(x);
		            G[x].push_back(i);
		            count++;
		        }
		    }
		}*/
		dfs(0,-1);
		memset(degree,0,sizeof(degree));
		for(i=0;i<n;i++)
		{
		    for(j=0;j<G[i].size();j++)
		    {
		        if(low[i]!=low[G[i][j]])
		         degree[low[i]]++;
		    }
		}
		/*dfs(0,-1);
		if(count1>1)
		count1--;*/
		int ans=0;
		for(int i=0;i<=n;i++)
			if(degree[i]==1)
				ans++;
		printf("Case %d: %d\n",kase++,(ans+1)/2);
	}
}
