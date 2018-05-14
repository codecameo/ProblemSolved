#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {

        int node[1001][1001];
        int totalNode;
        public:
        Graph(int n) {
            totalNode = n;
            clear();
        }

        void clear(){
            for(int i=0;i<totalNode; i++){
                for(int j=0;j<totalNode;j++)
                    node[i][j] = 0;
            }
        }

        void add_edge(int u, int v) {
            node[u][v]=1;
            node[v][u]=1;
        }

        int* shortest_reach(int start) {
            queue<int> q;
            int res[1001] = {-1};
            for(int i=0;i<totalNode;i++)
                res[i] = -1;
            int *point;
            q.push(start);
            bool table[1001] = {false};
            res[start] = 0;
            table[start] = true;
            while(!q.empty()){
                int nd = q.front();
                q.pop();
                for(int i=0;i<totalNode;i++){
                    if(node[nd][i] == 1 && !table[i]){
                        q.push(i);
                        table[i] = true;
                        res[i]= res[nd] + 6;
                    }
                }
            }
            point = res;
            return point;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        graph.clear();
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        int *distances = graph.shortest_reach(startId);
        for (int i = 0; i < n; i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
