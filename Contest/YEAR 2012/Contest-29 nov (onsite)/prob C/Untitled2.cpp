#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;

typedef pair< int, pii > state;

int grid[16][16], d[16][16];
int dr[] = {0, 0, 1, -1};
int dc[] = {-1, 1, 0, 0};

int main() {
	//READ("in.txt");
	//WRITE("output.txt");
	int test, cs, i, j, ans, ur, uc, vr, vc, tmp, R, C, si, sj;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
	    scanf("%d %d", &R, &C);
	    scanf("%d %d", &si, &sj);
	    for(i = 1; i <= R; i++) {
            for(j = 1; j <= C; j++) {
                scanf("%d", &grid[i][j]);
            }
	    }
	    MEM(d, 0x3f);
	    priority_queue< state, vector< state >, greater< state > > Q;
	    d[si][sj] = 0;
	    Q.push(state(d[si][sj], pii(si, sj)));
	    while(!Q.empty()) {
	        ur = Q.top().ss.ff;
	        uc = Q.top().ss.ss;
	        tmp = Q.top().ff;
	        Q.pop();
	        if(d[ur][uc] < tmp) continue;
	        for(i = 0; i < 4; i++) {
	            vr = ur + dr[i];
	            vc = uc + dc[i];
	            if(1 <= vr && vr <= R && 1 <= vc && vc <= C && grid[vr][vc] >= grid[ur][uc]) {
	                if(d[vr][vc] > max(d[ur][uc], grid[vr][vc] - grid[ur][uc])) {
	                    d[vr][vc] = max(d[ur][uc], grid[vr][vc] - grid[ur][uc]);
	                    Q.push(state(d[vr][vc], pii(vr, vc)));
	                }
	            }
	        }
	    }
	    ans = INF;
	    for(i = 1; i <= R; i++) {
	        ans = min(ans, d[i][1]);
	        ans = min(ans, d[i][C]);
	    }
	    for(j = 1; j <= C; j++) {
	        ans = min(ans, d[1][j]);
	        ans = min(ans, d[R][j]);
	    }
	    if(ans < INF) printf("%d. %d\n", cs, ans);
	    else printf("%d. IMPOSSIBLE\n", cs);
	}
	return 0;
}
