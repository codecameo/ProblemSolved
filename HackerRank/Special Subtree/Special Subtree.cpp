#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct data
{
    int u,v,cost;
    bool operator < (const data &p)const{
        return cost < p.cost;
    }
};

vector <data> v;
int node,edge,source;
int parent[3001];

void initParent()
{
    for(int i=0;i<node;i++)
        parent[i]=i;
}

void makeset(int n)
{
    parent[n]=n;
}

int find(int x)
{

    if(parent[x]==x) return x;
    return parent[x] = find(parent[x]);
}

int mst(int source)
{
    makeset(source);
    int count = 0,cost=0;

    for(int i = 0; i < v.size(); i++)
    {
        int x = find(v[i].u);
        int y = find(v[i].v);

        if(x != y)
        {
            parent[x] = y;
            count++;
            cost+= v[i].cost;
            if(count == node-1)
                break;
        }
    }

    return cost;
}

int main() {


    scanf("%d %d",&node,&edge);

    initParent();

    for(int i = 0;i < edge; i++)
    {
        data d;

        scanf("%d %d %d",&d.u,&d.v,&d.cost);

        v.push_back(d);
    }

    sort(v.begin(),v.end());

    /*for(int i = 0; i < v.size(); i++)
    {
        printf("%d %d %d\n",v[i].u,v[i].v,v[i].cost);
    }*/

    scanf("%d",&source);

    int res = mst(source);

    cout << res;

    return 0;
}


