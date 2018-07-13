#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
using namespace std;

int dis[1001],node;
vector<int> path[1001];

void clearDis(){

    for(int i=0;i<1001;i++)
    {
        dis[i]=-1;
    }

    for(int i=0;i<=node;i++)
    {
        while(path[i].size()!=0)
        {
            path[i].pop_back();
        }
    }
}

int main() {

    int tCase,edge,x,y,src;

    queue<int> q;
    scanf("%d",&tCase);
    while(tCase--)
    {
        clearDis();
        scanf("%d %d",&node,&edge);
        for(int i=1;i<=edge;i++)
        {
            scanf("%d %d",&x,&y);
            path[x].push_back(y);
            path[y].push_back(x);
        }

        /*for(int i=0;i<=node;i++)
        {
            printf("%d\n",i);
            for(int j=0;j<path[i].size();j++)
            {
                printf("%d ",path[i][j]);
            }
            printf("\n");
        }*/

        scanf("%d",&src);
        q.push(src);

        dis[src]=0;

        while(!q.empty())
        {
            int source=q.front();
            q.pop();
            int len = path[source].size();
            for(int j=0;j<len;j++)
            {
                if(dis[path[source][j]]==-1)
                {
                    q.push(path[source][j]);
                    dis[path[source][j]]=dis[source]+1;
                }
            }
        }

        for(int i=1;i<=node;i++)
        {
            if(src!=i)
            {
                int pathLen=-1;
                if(dis[i]!=-1)
                    pathLen=dis[i]*6;
                printf("%d ",pathLen);
            }
        }
        printf("\n");
    }

    return 0;
}

