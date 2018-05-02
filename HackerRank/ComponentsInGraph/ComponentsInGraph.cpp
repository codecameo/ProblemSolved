#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int parent[30001];

int getParent(int node){
    if(parent[node] == node) return node;
    return parent[node] = getParent(parent[node]);
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<=2*N;i++){
        parent[i] = i;
    }

    for(int i=0;i<N;i++){
        int x,y, parX, parY;
        cin>>x>>y;
        parX = getParent(x);
        parY = getParent(y);
        if(parX != parY)
            parent[parY] = parX;
    }

    int table[30001] = {0}, minN = 30001, maxN = 0;
    for(int i=0;i<=2*N;i++){
        int par = getParent(i);
        table[par]++;
    }

     for(int i=0;i<=2*N;i++){
        if(table[i] > 1)
        minN = min(minN, table[i]);
        maxN = max(maxN, table[i]);
    }

    cout<<minN<<" "<<maxN<<endl;
    return 0;
}
