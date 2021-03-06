#include <bits/stdc++.h>

#define pb push_back
#define MP make_pair
#define FOR(i,x,y) for(vlong i = (x) ; i <= 󰀀 ; ++i)
#define ROF(i,x,y) for(vlong i = 󰀀 ; i >= (x) ; --i)
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((vlong)(x).size())
#define NORM(x) if(x>=mod)x-=mod;

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;

#define NODE 100000
vector<int> adj[NODE+10];
int mod = 1e9+7;

vlong dp2 ( int s, int p, int c, int cur, int ally );

vlong dp ( int s, int p, int cur, int ally ) { ///This is f() in editorial

    vlong res = 0;

    res = dp2 ( s, p, 0, cur, ally ); ///Go and fetch some ally from the children

    return res;
}

int memo[NODE+10][2][2];
int done[NODE+10][2][2], cc = 1;

///Instead of recording s and c separately, we can simply store adj[s][c] in memo.
///No need to store p, since it is a rooted tree. Parent of a node is always same.

vlong dp2 ( int s, int p, int c, int cur, int ally ) { ///This is g() in editorial
    vlong res = 0;

    if ( c == adj[s].size() ) { ///Base case
        return ally;
    }

    int t = adj[s][c];

    ///Ignore back edge to parent of s. Rooted tree is not suppose to have this back edge anyway.
    if ( t == p ) {
        res = dp2 ( s, p, c + 1, cur, ally );
        return res;
    }


    if ( done[t][cur][ally] == cc ) return memo[t][cur][ally];
    done[t][cur][ally] = cc;

    ///For each child, we can make it ally with its parent
    ///And start independent sub-tree dp
    res = dp ( t, s, cur, 1 ) * dp2 ( s, p, c + 1, cur, 1 );
    res %= mod;

    ///Or, make it different
    vlong temp = dp ( t, s, 1 - cur, 0 ) * dp2 ( s, p, c + 1, cur, ally );
    temp %= mod;

    res += temp;
    NORM(res);

    return memo[t][cur][ally] = res;

}

void solution() {
    int n;
    scanf ( "%d", &n );

    FOR(i,1,n) {
        adj[i].clear();
    }

    FOR(i,0,n-2) {
        int a, b;
        scanf ( "%d %d", &a, &b );

        adj[a].pb ( b );
        adj[b].pb ( a );
    }

    cc++;
    vlong res = dp ( 1, 0, 0, 0 );
    res += dp ( 1, 0, 1, 0 );
    NORM(res);

    printf ( "%lld\n", res );
}

int main () {

    solution();

    return 0;
}
