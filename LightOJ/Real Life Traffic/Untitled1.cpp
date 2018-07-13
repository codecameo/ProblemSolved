/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/7/26 10:58:26
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())
const int MAXN = 10010;

bool inS[MAXN];
int t, n, m;
int top, S[MAXN];
int inx, low[MAXN], dfn[MAXN];
int s, belong[MAXN], degree[MAXN];
vector<int> maps[MAXN];

void tarjan(int u, int p)
{
    printf(":: %d %d\n",u,p);
        low[u] = dfn[u] = ++ inx;
        S[++ top] = u;
        inS[u] = 1;
        for (int i = 0; i < SZ(maps[u]); ++ i)
        {
                int v = maps[u][i];
                if (dfn[v] == -1)
                {
                        tarjan(v, u);
                        low[u] = min(low[u], low[v]);
                }
                else if (inS[v] && v != p)
                        low[u] = min(low[u], dfn[v]);
        }
        if (low[u] == dfn[u])
        {
                ++ s;
                printf("%d %d\n",u,s);
                int v;
                do
                {
                        v = S[top --];
                        inS[v] = 0;
                        belong[v] = s;
                } while (v != u);
        }
}

void shrink()
{
        memset(degree, 0, sizeof(degree));
        for (int u = 0; u < n; ++ u)
                for (int i = 0; i < SZ(maps[u]); ++ i)
                {
                        int v = maps[u][i];
                        if (belong[u] != belong[v])
                                ++ degree[belong[u]];
                }
}

int main()
{
        scanf("%d", &t);
        for (int l = 1; l <= t; ++ l)
        {
                scanf("%d%d", &n, &m);
                for (int i = 0; i < n; ++ i)
                        maps[i].clear();
                int u, v;
                for (int i = 0; i < m; ++ i)
                {
                        scanf("%d %d", &u, &v);
                        maps[u].push_back(v);
                        maps[v].push_back(u);
                }
                s = inx = top = 0;
                memset(dfn, -1, sizeof(dfn));
                memset(inS, 0, sizeof(inS));
                for (int i = 0; i < n; ++ i)
                        if (dfn[i] == -1){
                            printf("%di\n",i);
                                tarjan(i, -1);
                                printf("%d\n",s);
                        }
                shrink();
                for(int i=0;i<n;i++)
                {
                    printf("%d %d %d %d\n",dfn[i],low[i],inS[i],degree[i]);
                }
                printf("%d\n",s);
                int ans = 0;
                for (int i = 1; i <= s; ++ i)
                        if (degree[i] == 1)
                                ++ ans;
                printf("Case %d: %d\n", l, (ans + 1) >> 1);
        }
        return 0;
}
