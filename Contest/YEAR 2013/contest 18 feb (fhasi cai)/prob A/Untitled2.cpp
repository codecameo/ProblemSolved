#include <stdio.h>
int ar[101][101],dp[101][101],n,s;
vector<int> edge[101], cost[101];
const int infinity = 1000000000;

edge[i][j] = jth node connected with i
cost[i][j] = cost of that edge

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {

    int d[101];
    for(int i=0; i<100; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push( u );
    d[ source ] = 0;

    while( !q.empty() ) {
        u = q.top(); q.pop();
        int ucost = d[ u.city ];

        for(int i=1; i<=s; i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            // relaxing :)
            if( d[v.city] > v.dist ) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }

    return d[ destination ];
}
int main(){
int
scanf("%d",&t);
while(t--)
{
    scanf("%d %d",&n,&s);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
      scanf("%d",&ar[i][j]);
}
return 0;
}
