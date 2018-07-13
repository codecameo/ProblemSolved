#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include <set>
using namespace std;

#define cs c_str()
#define pb push_back
#define Forst(it,x)  for(map<string ,int>::iterator it=x.begin();it!=x.end();it++)
#define mem(a,s) memset(a,s,sizeof(a));
#define pi acos(-1.0)

#define LL long long
#define LLU long long unsigned
#define N 10000
#define MAX 0x3f
#define INF_MAX 2147483647
#define INF_MIN -2147483647

int main ()
{
    int n,m,i,j,k,a,b;
    int g[10010];
    mem(g,0);

    vector<int> V[10010];

    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        V[a].pb(b);
        V[b].pb(a);

        if(g[a]==0) g[a]=1;
        if(g[b]==0) g[b]=2;
    }

    scanf("%d %d",&a,&b);
    queue <int> Q;
    int vis[10009];
    mem(vis,-1);
    //vis[a]=0;
    Q.push(a);
    while(Q.size())
    {
        int u=Q.front();
        Q.pop();

        for(i=0;i<V[u].size();i++)
        {
            int v=V[u][i];

            if(vis[v]==-1)
            {
                if(g[u]!=g[v])
                {
                    vis[v]=vis[u]+1;
                }
                else vis[v]=vis[u];
                Q.push(v);

            }
        }
    }

    printf("%d\n",vis[b]);
}

