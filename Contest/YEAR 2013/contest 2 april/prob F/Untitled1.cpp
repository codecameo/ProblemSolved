/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/7/30 19:13:16
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())
typedef long long lint;
const int MAXN = 1002;
const lint MOD = 1000000007;

char C[MAXN];
bool S[MAXN];
int t, n, m;
lint dp[MAXN][MAXN];

int main()
{
        scanf("%d", &t);
        for (int l = 1; l <= t; ++ l)
        {
                scanf("%s", C);
                m = strlen(C);
                n = 0;
                for (int i = 0; i < m; ++ i)
                        if (C[i] != 'E')
                                S[++ n] = (C[i] == 'U');
                memset(dp, 0, sizeof(dp));
                dp[0][0] = 1;
                for (int i = 1; i <= n; ++ i)
                {
                        if (S[i])
                                for (int j = 1; j <= i; ++ j)
                                        dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] * j) % MOD;
                        else
                                for (int j = 0; j <= i; ++ j)
                                        dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j + 1] * (j + 1) * (j + 1)) % MOD;
                }
                printf("Case %d: %lld\n", l, dp[n][0]);
        }
        return 0;
}
