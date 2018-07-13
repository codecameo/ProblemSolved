#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> edges[100001];
int node;

struct{
    int weight;
    long int subtree;
}weights[100001];


void dfs(int root,int parent)
{
    weights[root].subtree=weights[root].weight;

    //printf("%d subtree %d\n",root,weights[root].subtree);

    for(int i=0;i<edges[root].size();i++)
    {
        int child = edges[root][i];
        if(child == parent)
            continue;
        //printf("node %d\n",child);
        dfs(child,root);
        weights[root].subtree+=weights[child].subtree;
        //printf("%d subtree %d\n",root,weights[root].subtree);
    }

}

int main(){

int tWeight=0,res;

scanf("%d",&node);

for(int i=1;i<=node;i++){
    scanf("%d",&weights[i].weight);
}

for(int i=0;i<node-1;i++)
{
    int x,y;
    scanf("%d %d",&x,&y);
    //printf("Nodes %d %d\n",x,y);
    edges[x].push_back(y);
    edges[y].push_back(x);
}

dfs(1,0);

tWeight = weights[1].subtree;
res = tWeight;

//printf("\nTotal %d\n",tWeight);

for(int i=1;i<=node;i++)
{
    for(int j=0;j<edges[i].size();j++)
    {
        int m = abs(tWeight - (2*weights[edges[i][j]].subtree));
        //printf("res %d\n",m);
        res = min(m,res);
    }
}

printf("%d\n",res);

return 0;
}
