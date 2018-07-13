
#include <cstdio>
#include <cmath>

#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

#include <algorithm>

using namespace std;

int read() { int n; scanf("%d", &n); return n; }

#define REP(i,n) for (int i=0, ___=(n); i<___; ++i)
#define FOR(i,a,b) for (int i=(a), ___=(b); i<=___; ++i)
#define FORD(i,a,b) for (int i=(a), ___=(b); i>=___; ++i)

typedef long long ll;
typedef pair<int, int> PII;
#define mp make_pair


const int N = 500000;
char s[N+1];

void change(int n, vector<int> &v) {
	vector<int> res(1, 1);
	int j;
	for (int i=0; i<v.size(); i=j) {
		int p = v[i];
		j = i+1;
		int cnt = 1;
		while (j < v.size() && v[j] == v[i]) ++cnt, ++j;
		cnt *= 2;
		REP(x, res.size()) {
			long long cur = res[x];
			for (int k=1; k<=cnt; ++k) {
				cur *= p;
				if (cur >= n) break;
				res.push_back(cur);
			}
		}
	}
	std::swap(v, res);
}

int main() {
	int n = read();
	scanf("%s", s);

	vector<int> p(n+1, 1);
	vector<vector<int> > d(n+1);
	vector<int> val(n+1);
	FOR(i, 2, n) val[i] = i;

	p[0] = p[1] = 0;
	for (int i=2; i<=n; ++i) if (p[i]) {
		d[i].push_back(i);
		val[i] = 1;
		for (int j=i+i; j<=n; j+=i) {
			p[j] = 0;
			while (val[j] % i == 0) {
				val[j] /= i;
				d[j].push_back(i);
			}
		}
	}

	FOR(i, 1, n) change(i, d[i]);

	int res = 0;
	REP(j, n) {
		if (s[j] != 'b') continue;
		REP(a, d[j+1].size()) {
			int i = d[j+1][a];
			ll kk = 1LL * (j+1) * (j+1) / i;
			--i;
			--kk;
			if (kk >= n) continue;
			int k = kk;
//printf("%d %d %d\n", i, j, k);
			if (s[i] == 'a' && s[k] == 'c') ++res;
			if (s[i] == 'c' && s[k] == 'a') ++res;
		}
	}
	printf("%d\n", res);

	return 0;
}
