#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 3010
int n,m,timer,cost;
vector<int>GRAPH[MAXN];
int f[MAXN];
int d[MAXN],cnt;
bool vis[MAXN];
bool ar_ch[MAXN];

void reset()
{
    for(int i=0;i<MAXN;i++) GRAPH[i].clear();
    memset(vis,false,sizeof(vis));
    memset(f,false,sizeof(f));
    memset(d,false,sizeof(d));
    memset(ar_ch,false,sizeof(ar_ch));
    timer=0;
    cnt=0;
}

void get_input()
{
    scanf("%d %d %d",&n,&m,&cost);
    int i,a,b;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        GRAPH[a].push_back(b);
        GRAPH[b].push_back(a);
    }
}

void ARTICULATION_POINTS(int u,int p)
{
    vis[u]=1;
    timer=timer+1;
    d[u]=f[u]=timer;
    int child=0,to;
    for(int i=0;i<GRAPH[u].size();i++)
    {
        to=GRAPH[u][i];
        if(to==p)   continue;
        if(vis[to]) f[u]=min(f[u],d[to]);
        else
        {
            ARTICULATION_POINTS(to,u);
            f[u]=min(f[u],f[to]);
            if(f[to]>=d[u] && p!=-1)
            {
                if(ar_ch[u]==false) cnt++;
                ar_ch[u]=true;
            }
            child++;
        }
    }
    if(p==-1 && child>1)
    {
        if(ar_ch[u]==false) cnt++;
        ar_ch[u]=true;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        reset();
        get_input();
        ARTICULATION_POINTS(1,-1);
        printf("%d\n",cnt*cost);
    }
}
