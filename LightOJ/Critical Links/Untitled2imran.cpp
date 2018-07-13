#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#define MAX 10010
using namespace std;
struct edges{
    int a,b;
    bool operator < ( const edges& p ) const
    {
        if(a==p.a)  return b < p.b;
        return a < p.a;
    }
};

edges get;
int color[MAX], d[MAX], p[MAX], f[MAX], low[MAX], t, n, m;
vector<int>G[MAX];
vector<edges> articPoints;

void reset();
void get_input();
void DFS();
void DFS_VISIT(int u);

int main()
{
    //freopen("input.txt", "r", stdin);
    int sz,T,i,CASE=0;
    scanf("%d",&T);
    while(T--)
    {
        reset();
        get_input();
        DFS();
        printf("Case %d:\n%d critical links\n",++CASE,articPoints.size());
        sort(articPoints.begin(),articPoints.end());
        sz=articPoints.size();
        for(i=0;i<sz;i++)
        {
            printf("%d - %d\n",articPoints[i].a,articPoints[i].b);
        }
    }
    return 0;
}

void get_input()
{
    scanf("%d",&n);
    int i,a,b,j;
    for(i=0;i<n;i++)
    {
        scanf("%d (%d)",&a,&m);
        for(j=0;j<m;j++)
        {
            scanf("%d",&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
    }
}
void reset()
{
    for(int i=0;i<MAX;i++) G[i].clear();
    memset(color,false,sizeof(color));
    memset(d,false,sizeof(d));
    memset(p,false,sizeof(p));
    memset(f,false,sizeof(f));
    memset(low,false,sizeof(low));
    articPoints.clear();
    t=0;
}
void DFS()
{
    for(int u=0; u<n; u++)
        if(color[u]==0) DFS_VISIT(u);
}
void DFS_VISIT(int u)
{
    t = t + 1;
    d[u] = low[u] = t;
    color[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(color[v] == 0)
        {
            p[v] = u;
            DFS_VISIT(v);
            if(d[u] == 1)
            {
                if(G[u].size() >= 2 && low[v] > d[u])
                {
                    if(u<v)
                    {
                        get.a=u;
                        get.b=v;
                    }
                    else
                    {
                        get.a=v;
                        get.b=u;
                    }
                    articPoints.push_back(get);
                }
            }
            else if(low[v] > d[u])
            {
                if(u<v)
                {
                    get.a=u;
                    get.b=v;
                }
                else
                {
                    get.a=v;
                    get.b=u;
                }
                articPoints.push_back(get);
            }
            low[u] = min(low[u],low[v]);
        }
        else if(p[u] != v)
        {
            low[u] = min(low[u],d[v]);
        }
    }
    color[u] = 2;
    t = t + 1;
    f[u] = t;
}
