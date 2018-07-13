#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> edges[100001];
int n;
int res;
int table[100001];

int dfs(int index,int parent){

    //printf("Index %d\n",index);

    int child = 1;
    for(int i=0; i<edges[index].size(); i++){
        //if(edges[index][i]!= parent)
            child=child*dfs(edges[index][i],index);
    }

    //printf("Return %d Res %d\n",index,child*table[index]);
    return (child*table[index])% 1000000007;
}

int main(){
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        edges[u].push_back(v);
        //edges[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        int child=0;
        int nodeSize = edges[i].size();
        for(int j=0;j< nodeSize;j++){
            if(edges[edges[i][j]].size()>0)
            child++;
        }

        if(child == 0)
            table[i]=1;
        else{
            table[i] = pow(2,child);
            /*if(child==nodeSize && i == 1){
                table[i]--;
            }*/
        }
    }

    for(int i=1 ; i<=n;i++){
        printf("%d -> %d\n",i,table[i]);
    }

    printf("%d",dfs(1,0)*2);


    return 0;
}

