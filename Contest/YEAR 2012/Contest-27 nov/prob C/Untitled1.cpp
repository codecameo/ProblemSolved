#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


#define Clear(a) memset(a,0,sizeof(a))

#define M 200000 + 10

struct edge{
    int u,v,w;
    bool operator < ( const edge& p ) const
    {
        return w < p.w;
    }
};

vector < edge > GRAPH;
int parent[M];

int find(int x)
{
    if(parent[x]==x)    return x;
    return parent[x] = find(parent[x]);
}

int mst(int n,int m)
{
    sort(GRAPH.begin(), GRAPH.end());

    int i, u, v,total=0;
    for(i=0;i<n+2;i++)    parent[i] = i;

    for(i=0; i<m; i++)
    {
        u = find(GRAPH[i].u);
        v = find(GRAPH[i].v);
        if(u != v)
        {
            total += GRAPH[i].w;
            parent[u] = parent[v];
        }
    }
    return total;
}

void reset(int n)
{
    GRAPH.clear();
    Clear(parent);
    //for(int i=0;i<n+1;i++)    parent[i]=i;
}

int main()
{
    int i,u,v,w,n,m,total;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        reset(n);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            edge get;
            get.u=u;get.v=v;get.w=w;
            GRAPH.push_back(get);
        }
        printf("%d\n",mst(n,m));
    }
}
