#include <stdio.h>
#include <iostream>
#define MAXN   100005
using namespace std;
int par[MAXN], sz[MAXN];

void init(int n){
    int i;
    for(i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int findParent(int idx){
    if(par[idx] == idx) return idx;
    int p = par[idx];
    int newP = findParent(p);
    if(p != newP){
        sz[newP] += sz[p];
        sz[p] = 0;
    }
    return par[idx] = newP;
}

void Union(int u, int v){
    int par_u = findParent(u);
    int par_v = findParent(v);
    if(par_u == par_v) return;
    par[par_u] = par_v;
    sz[par_v] += sz[par_u];
    sz[par_u]=0;
}

int main(){
    int N,Q;
    cin>>N>>Q;
    init(N);
    while(Q--){
        char key;
        int x,y;
        cin >> key;
        if(key == 'M'){
            cin >> x>>y;
            Union(x,y);
        }else{
            cin >> x;
            cout<<sz[findParent(x)]<<endl;
        }
    }
    return 0;
}
