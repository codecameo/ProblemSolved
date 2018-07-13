#include <stdio.h>
#include <memory.h>
#include <queue>
#define Min(x,y) (((x)<(y))?(x):(y))
#define MAXN 21004
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int d[MAXN];
bool vis[MAXN];
typedef struct{
	int v,w;
}node;
vector< vector<node> > arc;
typedef struct point{
	friend bool operator<(point a,point b)
	{	return a.w>b.w;	}
	int w,id;
}point;
void dijkstra(int s,int t)
{
	int i,u,v;
	point p;
	priority_queue<point> q;
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	p.w=0; p.id=s;
	q.push(p);
	while(!q.empty())
	{
		p=q.top(); q.pop();
		u=p.id;
		d[u]=p.w;
		if(u==t) return;
		if(vis[u]) continue;
		vis[u]=1;
		for(i=0;i<arc[u].size();i++)
		{
			v=arc[u][i].v;
			if(!vis[v] && d[v]>d[u]+arc[u][i].w)
			{
				d[v]=d[u]+arc[u][i].w;
				p.w=d[v]; p.id=v;
				q.push(p);
			}
		}
	}
}
int main()
{
	int T,u,v,w,s,t,ncase=0;
	node p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&s,&t);
		arc.clear();
		arc.resize(n+2);
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			p.v=v; p.w=w;
			arc[u].push_back(p);
			p.v=u; p.w=w;
			arc[v].push_back(p);
		}
		dijkstra(s,t);
		if(d[t]==INF) printf("Case #%d: unreachable\n",++ncase);
		else printf("Case #%d: %d\n",++ncase,d[t]);
	}
	return 0;
}
