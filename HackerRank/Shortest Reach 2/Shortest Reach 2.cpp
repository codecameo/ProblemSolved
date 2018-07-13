#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int inf = 300000001;
vector<int> edge[3001],cost[3001];
int node,edges;

struct data
{
    int city,dist;

    bool operator < (const data &p) const
    {
        return dist > p.dist;
    }

};

void dijkstra(int source)
{
    int d[30001],visit[30001];
    for(int i=0; i< 3001; i++)
    {
        d[i]=inf;
        visit[i]=0;
    }

    priority_queue <data> q;
    data u,v;
    u.city = source;
    u.dist=0;
    q.push(u);
    d[source] = 0;

    while(!q.empty())
    {
        u = q.top();
        q.pop();

        if(visit[u.city]) continue;
        visit[u.city] = 1;

        int uCost = d[u.city];

        for(int i=0;i<edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i]+uCost;

            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }


    for(int i = 1; i<= node; i++)
    {
        if(i == source) continue;

        int c = d[i];
        if(c == inf)
            c=-1;
        printf("%d ",c);
    }
    printf("\n");

}


int main()
{
    int tKase;

    scanf("%d",&tKase);
    while(tKase--)
    {
        scanf("%d %d",&node,&edges);

        int x,y,z;

        for(int i = 1; i<=edges; i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            edge[x].push_back(y);
            edge[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);

        }

        int source;

        scanf("%d",&source);

        dijkstra(source);

        for(int i=0;i<=node; i++)
        {
            edge[i].clear();
            cost[i].clear();
        }


    }
    return 0;
}
