#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#define MAX 10100
using namespace std;
int Stack[MAX], top;
int Index[MAX], Lowlink[MAX], Onstack[MAX];
int Component[MAX],degree[MAX];
int idx, components;
vector< int > G[MAX];
//vector< pair< int, int > > Bridges;
//int low[MAX],vis[MAX],used[MAX],degree[MAX],dfstime;
//bool flag=0;
int count,m,n,count1;
void reset()
{
    int i;
	for(i=0;i<=MAX;i++)
	G[i].clear();
	idx=0;
	//memset(cut,0,sizeof(cut));
}
void tarjan(int u,int p) {
    //printf(":: %d %d\n",u,p);
    int v, i;
    Index[u]=Lowlink[u]=idx++;
    Stack[top++]=u;
    Onstack[u] = 1;
    for(i = 0; i < G[u].size(); i++) {
        v = G[u][i];
        if(Index[v]==-1) {
            tarjan(v,u);
            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
        }
        else if(Onstack[v] && p!=v)
        Lowlink[u] = min(Lowlink[u], Index[v]);
    }
    if(Lowlink[u] == Index[u]) {
        components++;
        //printf("%d %d\n",u,components);
        do {
            v = Stack[--top];
            Onstack[v] = 0;
            Component[v] = components;
        } while(u != v);
    }
}
void shrink()
{
        memset(degree, 0, sizeof(degree));
        for (int u = 0; u < n; ++ u)
                for (int i=0;i<G[u].size();++i)
                {
                        int v = G[u][i];
                        if (Component[u] != Component[v])
                                ++ degree[Component[u]];
                }
}
void findSCC() {
    components = top = idx = 0;
    //SET(Index); CLR(Onstack); MEM(Lowlink, 0x3f);
    memset(Lowlink,0x3f,sizeof(Lowlink));
	memset(Index,-1,sizeof(Index));
	memset(Onstack,0,sizeof(Onstack));
    for(int i = 0; i < n; i++)
        if(Index[i]==-1)
        {
            //printf("%di\n",i);
            tarjan(i,-1);
            //printf("%dc\n",components);
        }
}

int main()
{
	int t,kase=1,i,a,b,x,j;
	scanf("%d",&t);
	while(t--)
	{
		reset();
        scanf("%d %d",&n,&m);
            for(i=0;i<m;i++)
            {
                scanf("%d %d",&a,&b);
                G[a].push_back(b);
                G[b].push_back(a);
            }
		findSCC();
		shrink();
		/*for(i=0;i<n;i++)
		    printf("%d %d %d %d\n",Index[i],Lowlink[i],Onstack[i],degree[i]);*/
		int ans=0;
		//printf("%d\n",components);
		for(int i=1;i<=components;i++)
			if(degree[i]==1)
				ans++;
		printf("Case %d: %d\n",kase++,(ans+1)/2);
	}
}
