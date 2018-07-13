#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;

#define INF 0x3f3f3f3f
const int N = 100005;
//freopen ("in.txt", "r", stdin);
vector <int> e[N], nex;
int n;
long long ret;

int dfs (int now){
	if (e[now].size () == 0) return 1;
	int size = e[now].size (), sum = 0, num;
	for (int i = 0; i < size; ++ i){
		num = dfs (e[now][i]);
		if (i != 0)
			ret += (sum * num);
		sum += num;
	}
	return sum + 1;
}

int main (){
	int Case, from, to;
	scanf ("%d", &Case);
	for (int T = 1; T <= Case; ++ T){
		scanf ("%d", &n);
		for (int i = 1; i <= n; ++ i) e[i].clear ();
		for (int i = 1; i < n; ++ i){
			scanf ("%d%d", &from, &to);
			e[from].push_back (to);
		}
		ret = 0;
		int tot = dfs (1);
		printf ("Case %d: %d %lld\n", T, tot - 1, ret);
	}
	return 0;
}
