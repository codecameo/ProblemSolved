#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int node,edge,dist[401][401];
int inf = 10000000;

void initDist()
{
    for(int i = 0; i <=node; i++)
    {
        for(int j = 0; j<=node;j++)
        {
            //dist[i][j]=inf;
            dist[j][i]=inf;
            if(j==i)
            dist[j][i]=0;

        }
    }
}


int main() {

    scanf("%d %d",&node,&edge);

    initDist();

    int x,y,cost;

    for(int i = 0; i < edge; i++)
    {
        scanf("%d %d %d",&x,&y,&cost);
        //dist[y][x]=cost;
        dist[x][y]=cost;
    }

    for(int k = 1; k<=node; k++)
        for(int i = 1; i<=node; i++)
            for(int j = 1; j<=node; j++)
                if(dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];


    int query;

    scanf("%d",&query);

    for(int i = 0; i < query; i++)
    {
        scanf("%d %d",&x,&y);
        int cost = dist[x][y];
        if(cost == inf)
            cost = -1;

        printf("%d\n",cost);
    }

    return 0;
}

