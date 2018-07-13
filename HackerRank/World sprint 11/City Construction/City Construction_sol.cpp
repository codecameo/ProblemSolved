#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define D(x)        cerr << #x " = " << (x) << '\n'
#define DBG         cerr << "Hi" << '\n'
#define pb          push_back
#define PI          acos(-1.00)
#define xx          first
#define yy          second
#define eps         1e-9

typedef unsigned long long int ULL;
typedef long long int LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;


inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction

#define MAX     50000
int n, m;
vector<int>E[MAX+10], rev[MAX+10], G[MAX+10];
vector<pii>query;
vector<int>V;
bool vis[MAX+10];
int totalComp, compOf[MAX+10];

void dfs(int node)
{
    vis[node] = true;
    for(auto v = E[node].begin(); v!= E[node].end(); v++)
    {
        if(!vis[*v])
            dfs(*v);
    }
    V.pb(node);
}

void dfs2(int node, int compNum)
{
    vis[node] = true;
    compOf[node] = compNum;
    for(auto v = rev[node].begin(); v!=rev[node].end(); v++)
    {
        if(!vis[*v])
            dfs2(*v,compNum);
    }
}

void SCC()
{
    /// build reverse graph
    for(int u = 1; u<=n; u++)
    {
        for(auto v = E[u].begin(); v != E[u].end(); v++)
        {
            rev[*v].pb(u);
        }
    }

    /// topological sort
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i])
            dfs(i);
    }

    for(int i=0;i<n;i++){
        printf("%d ",V[i]);
    }

    mem(vis,false);
    totalComp = 0;
    for(int i = (int)V.size()-1; i>=0; i--){
        int u = V[i];
        if(!vis[u])
            totalComp++,dfs2(u,totalComp);
    }


    for(int i=1;i<=n;i++){
        printf("node -> %d com -> %d\n",i,compOf[i]);
    }

    for(int u = 1; u<=n; u++){
        for(auto v = E[u].begin(); v!=E[u].end(); v++){
            G[compOf[u]].pb(compOf[*v]);
        }
    }
}

bitset<MAX+5>dp[MAX+5];

void call(int node){
    vis[node] = true;
    dp[node][node] = true;
    for(auto v = G[node].begin(); v != G[node].end(); v++){
        if(!vis[*v])
            call(*v);
        dp[node] |= dp[*v];
    }
}

void solve()
{
    SCC();
    mem(vis,0);
    for(int u = 1; u<=totalComp; u++){
        if(!vis[u])
            call(u);
    }

    for(auto cur = query.begin(); cur != query.end(); cur++){
        int u = compOf[(*cur).xx];
        int v = compOf[(*cur).yy];
        if(dp[u][v] == true)
            puts("Yes");
        else
            puts("No");
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int i, j, cs, t, u, v, type, x, d, q;
    sff(n,m);
    FRE(i,1,m)
    {
        sff(u,v);
        E[u].pb(v);
    }
    sf(q);
    FRE(i,1,q)
    {
        sf(type);
        if(type == 1)
        {
            sff(x,d);
            n++;
            if(d == 0)
                u = x, v = n;
            else
                u = n, v = x;
            E[u].pb(v);
        }
        else
        {
            sff(u,v);
            query.pb({u,v});
        }
    }
    solve();
    return 0;
}


