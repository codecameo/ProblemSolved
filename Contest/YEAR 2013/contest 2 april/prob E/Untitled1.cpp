#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int maxn = 101119;
typedef long long LL;
struct edge {
	int v, nxt;
} e[maxn];
int nm, w[maxn];
void init (int n) {
	nm = 0;
	memset (w, -1, sizeof (int) * (n+9));
}
void add (int u, int v) {
	e[nm].v = v, e[nm].nxt = w[u];
	w[u] = nm ++;
}
LL ans;
int dfs (int u) {
	int v;
	int sum = 0, k;
	for (int i = w[u]; ~i; i = e[i].nxt) {
		v = e[i].v;
		k = dfs (v);
		ans += (LL) k * sum;
		sum += k;
	}
	return sum+1;
}
int main () {
	int t, n, x, y;
	scanf ("%d", &t);
	int cas = 1;
	while (t --) {
		scanf ("%d", &n);
		init (n);
		for (int i = 0; i < n-1; ++ i) {
			scanf ("%d%d", &x, &y);
			add (x, y);
		}
		ans = 0;
		dfs (1);
		printf ("Case %d: %d %lld\n", cas ++, n-1, ans);
	}
    return 0;
}
