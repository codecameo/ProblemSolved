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
        return cost > p.cost;
    }
};

vector <data> v;
int node,k,source,machine;
int parent[100001];

bool compare(data a,data b)
{
    return a.cost > b.cost;
}

void initParent()
{
    for(int i=0;i<node;i++)
        parent[i]=i;

}

void makeset(int n)
{
    parent[n]=n;
}

int find(int x){

    if(parent[x]==x) return x;
    else if(parent[x]==-1) return -1;
    return parent[x] = find(parent[x]);
}

int mst()
{
    //makeset(source);
    int count = 0,cost=0;

    for(int i = 0; i < v.size(); i++)
    {
        //printf("%d %d %d\n",v[i].u,v[i].v,v[i].cost);

        int x = find(v[i].u);
        int y = find(v[i].v);

        //printf("X=> %d y=> %d\n",x,y);

        if(x != y)
        {
            if(y==-1)
                parent[x] = y;
            else //if(x==-1)
                parent[y]=x;

            //printf("New Parent %d=> %d %d=> %d\n",v[i].u,parent[x],v[i].v,parent[y]);

            /*else
                parent[x] = y;

            count++;
            cost+= v[i].cost;
            if(count == node-1)
                break;*/
        }
        else{
            cost+=v[i].cost;
            //printf("Cost increased %d\n",cost);
        }
    }

    return cost;
}

int main() {


    scanf("%d %d",&node,&machine);

    initParent();

    for(int i = 0; i<node-1; i++)
    {
        data d;

        scanf("%d %d %d",&d.u,&d.v,&d.cost);

        v.push_back(d);
    }

    sort(v.begin(),v.end());

    /*printf("\n");
    for(int i = 0; i < v.size(); i++)
    {
        printf("%d %d %d\n",v[i].u,v[i].v,v[i].cost);
    }*/

    for(int i = 0; i< machine; i++)
    {
        int m;
        scanf("%d",&m);
        parent[m]=-1;
    }

    //scanf("%d",&source);

    int res = mst();

    cout << res;

    return 0;
}


