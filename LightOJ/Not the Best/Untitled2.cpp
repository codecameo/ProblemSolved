#define mx 5010
#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
vector<long long int>g[mx],cost[mx];
const long long int inf=3999000;
struct node
{
    long long int u,w;
    node(long long int a,long long int b){u=a; w=b;}
    bool operator < ( const node& p ) const {      return w > p.w;   }
};
long long int d[mx],par[mx];
long long int dijkstra(long long int n)
{
    memset(d,inf,sizeof(d));  //অনেক বড় একটা মান বসাতে!
    memset(par,-1,sizeof(par));
    bool flag=0;

    priority_queue<node>q;
    q.push(node(1,0));
    d[1]=0;
    while(!q.empty())
    {
        node top=q.top(); q.pop();
        long long int u=top.u;
        printf("node -> %lld %lld\n",top.u,top.w);
        if(u==n-1)
        {
            if(flag==0)
            {
                flag=1;
                //continue;
            }
            else if(flag==1)
            return top.w;
        }
        for(int i=0;i<(int)g[u].size();i++)
        {
            puts("jhdkw");
            long long int v=g[u][i];
            printf("%lld %lld\n",v,d[v]);
            if(d[u]+cost[u][i]<d[v])
            {
                puts("jhd");
                printf("d[v]-> %lld d[u]+cost[u][i]-> %lld v-> %lld\n",d[v],d[u]+cost[u][i],v);
                d[v]=d[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    puts("hhd");
    return -1;
}
int main(){
    long long int n,e,u,v,w;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(v);
        g[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);

    }
    u=n;v=n+1;w=inf;
    g[u].push_back(v);
    g[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
    n++;
    long long int ret=dijkstra(n);
    printf("%lld\n",ret);
    if(ret==-1) puts("No path!");
    else
    {
        int u=n;
        vector<int>out;
        while(u!=-1)
        {
            out.push_back(u);

            u=par[u];

        }
        reverse(out.begin(),out.end());
        for(int i=0;i<(int)out.size();i++)
            cout<<out[i]<<" ";
        puts("");

    }
}
