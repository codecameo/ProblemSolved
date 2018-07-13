#include <bits/stdc++.h>
using namespace std;

set<int> edges[300001];
int parent[300001];
long long nodes[300001];

bool compare(int a, set<int> &S1, int b, set<int> &S2){
	if (S1 == S2)
		return true;
	int x = S1.count(b);
	int y = S2.count(a);
	S1.erase(b);
	S2.erase(a);
	bool res = S1 == S2;
	if (x == 1)
		S1.insert(b);
	if (y == 1)
		S2.insert(a);
	return res;
}

int findParent(int i){
    if(i == parent[i]) return i;
    return parent[i] = findParent(parent[i]);
}

int main() {
    int n;
    int e;
    cin >> n >> e;
    pair<int, int> edgePair[e];
    for(int i = 0; i < e; i++){
        int a;
        int b;
        cin >> a >> b;
        edges[a].insert(b);
        edges[b].insert(a);
        edgePair[i] = make_pair(a,b);
    }

    for(int i=0;i<=n;i++){
        parent[i]=i;
        nodes[i]=1;
    }

    for(int i=0;i<e;i++){
        int x = edgePair[i].first;
        int y = edgePair[i].second;
        if(compare(x,edges[x],y,edges[y])){
            x = findParent(x);
            nodes[x]+=nodes[y];
            nodes[y] = 0;
            parent[y] = x;
        }
    }


    map <set<int>,int> m;

    for(int i=1;i<=n;i++){
        if(m.count(edges[i]) == 0){
            //printf("i -> %d\n",i);
            m[edges[i]] = i;
        }else{
            int x = findParent(m[edges[i]]);
            int y = i;
            if(edges[x]==edges[y]){
                nodes[x]+=nodes[y];
                nodes[y] = 0;
                parent[y] = x;
            }
            //printf("x -> %d y -> %d nodes[%d] = %d\n",x,y,x,nodes[x]);
            //printf("x parent -> %d Y parent -> %d\n",parent[x], parent[y]);
        }
    }

    long long sum = 0;
    for(int i=1;i<=n;i++){
        sum+=(nodes[i]*(nodes[i]-1)/2);
    }
    cout<<sum;

    return 0;
}
