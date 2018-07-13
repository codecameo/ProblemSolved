#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector <pair<int,int>>query;
vector<int> top_sort;
bitset<50001> table;
int nodeMapping[50001];
vector<int> acyclicGraph[50001];
bitset<50001> nodes[50001];

struct Edge{
    vector<int> backEdge;
    vector<int> edges;
}nodeTrack[50001];

void clearTable(){
    table=false;
}

void topoDfs(int node){
    //printf("Node %d\n",node);
    table[node]=true;
    int len = nodeTrack[node].edges.size();

    for(int i=0;i<len;i++){
        int v= nodeTrack[node].edges[i];
        if(!table[v]){
            topoDfs(v);
        }
    }
    top_sort.push_back(node);
}

void resDfs(int node){
    table[node]=true;
    nodes[node][node]=true;
    int len = acyclicGraph[node].size();

    for(int i=0;i<len;i++){
        int v = acyclicGraph[node][i];
        if(!table[v]){
            resDfs(v);
            nodes[node]|=nodes[v];
        }
    }
}

void dfs(int node,int child){
    //printf("Node %d\n",node);
    nodeMapping[node]=child;
    table[node] = true;
    int len = nodeTrack[node].backEdge.size();
    for(int i=0;i<len;i++){
        int nd= nodeTrack[node].backEdge[i];
        if(!table[nd]){
            dfs(nd,child);
        }
    }
}


void insertNode(int u,int v){
    nodeTrack[v].backEdge.push_back(u);
    nodeTrack[u].edges.push_back(v);
}

void callDfs(int u,int v){
    clearTable();
    table[u]=true;
    dfs(u,v);
}

int main() {
    cin >> n >> m;
    for(int a0 = 0; a0 < m; a0++){
        int u;
        int v;
        cin >> u >> v;
        insertNode(u,v);
    }

    int q;
    int x;
    int y;
    int type;
    cin >> q;

    for(int a0 = 0; a0 < q; a0++){
        cin >> type >> x >> y;
        //cout<<"Yes"<<endl;
        if(type==1){
            n++;
            if(y==0){
                insertNode(x,n);
            }else{
                insertNode(n,x);
            }

        }else if(type==2){
            query.push_back({x,y});
        }
    }

    clearTable();
    for(int i=1;i<=n;i++){
        if(!table[i])
            topoDfs(i);
    }

    //for(int i=0;i<n;i++)
      //  printf("%d ",top_sort[i]);
    //printf("\n");

    clearTable();
    int nodeCount=0;
    for(int i=n-1;i>=0;i--){
        if(!table[top_sort[i]]){
            nodeCount++;
            //printf("Calling dfs %d\n",top_sort[i]);
            dfs(top_sort[i],nodeCount);
        }
    }
    clearTable();

    //for(int i=1;i<=n;i++)
   //     printf("%d ",nodeMapping[i]);
    //printf("\n");

    for(int i=1;i<=n;i++){
        int ux = nodeMapping[i];
        for(auto j= nodeTrack[i].edges.begin(); j!= nodeTrack[i].edges.end(); j++){
            int vx = nodeMapping[*j];
            //printf("%d %d\n",ux,vx);
            if(vx!=ux)
                acyclicGraph[ux].push_back(vx);
        }
    }

    clearTable();
    for(int i=1;i<=nodeCount;i++){
        if(!table[i])
            resDfs(i);
    }

    for(auto it = query.begin();it!=query.end();it++){
        int x1 = nodeMapping[(*it).first];
        int x2 = nodeMapping[(*it).second];
        if(nodes[x1][x2]){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}

