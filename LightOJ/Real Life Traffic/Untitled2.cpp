#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int kMaxn = 10007;
const int kMaxm = 40007;

struct Edge {
    int id;
    int u, v;
};

int n, m;
int cnt, cut, first[kMaxn], next[kMaxm];
Edge e[kMaxm];
bool bridge[kMaxm];
int dfscnt, dfsn[kMaxn], low[kMaxn];

void Clear () {
    cnt = -1;
    memset ( first, -1, sizeof ( first ) );
}

void AddEdge ( int u, int v, int id ) {
    cnt++; e[cnt].u = u;
    e[cnt].v = v;
    next[cnt] = first[u]; first[u] = cnt;
    cnt++; e[cnt].u = v;
    e[cnt].v = u;
    next[cnt] = first[v]; first[v] = cnt;
    e[cnt-1].id = e[cnt].id = id;
}

void dfs ( int u, int father ) {
    dfsn[u] = low[u] = ++dfscnt;
    for ( int i = first[u]; i != -1; i = next[i] ) {
        int v = e[i].v;
        if ( v == father ) continue;
        if ( !dfsn[v] ) {
            dfs ( v, u );
            low[u] = min ( low[u], low[v] );
            if ( low[v] > dfsn[u] ) {
                bridge[e[i].id] = true;
                cut++;
            }
        } else low[u] = min ( low[u], dfsn[v] );
    }
}

void Tarjan () {
    cut = dfscnt = 0;
    memset ( dfsn, 0, sizeof ( dfsn ) );
    memset ( bridge, 0, sizeof ( bridge ) );

    for ( int i = 1; i <= n; i++ )
        if ( !dfsn[i] )
            dfs ( i, -1 );
}

void Input () {
    Clear ();
    scanf ( "%d%d", &n, &m );
    for ( int i = 1; i <= m; i++ ) {
        int u, v;
        scanf ( "%d%d", &u, &v );
        u++; v++;
        AddEdge ( u, v, i );
    }
}

int n2, id[kMaxn], degree[kMaxn];
bool visited[kMaxn];

void dfs2 ( int u ) {
    visited[u] = true;
    id[u] = n2;
    for ( int i = first[u]; i != -1; i = next[i] )
        if ( !bridge[e[i].id] ) {
            int v = e[i].v;
            if ( visited[v] ) continue;
            dfs2 ( v );
        }
}

void Solve () {
    if ( cut == 0 ) {
        printf ( "%d\n", 0 );
        return;
    }
    n2 = 0;
    memset ( visited, false, sizeof ( visited ) );
    for ( int i = 1; i <= n; i++ )
        if ( !visited[i] ) {
            n2++;
            dfs2 ( i );
        }

    //printf ( "\ncut = %d\nn2 = %d\n", cut, n2 );

    memset ( degree, 0, sizeof ( degree ) );
    for ( int i = 0; i <= cnt; i++ )
        if ( bridge[e[i].id] ) {
            degree[id[e[i].u]]++;
            degree[id[e[i].v]]++;
        }
    int ans = 0;
    for ( int i = 1; i <= n2; i++ )
        if ( degree[i] == 2 )
            ans++;
    printf ( "%d\n", (ans+1)>>1 );
}

int main () {
    int T;
    scanf ( "%d", &T );
    for ( int case_num = 1; case_num <= T; ) {
        printf ( "Case %d: ", case_num++ );
        Input ();
        Tarjan ();
        Solve ();
    }
    return 0;
}
