#include <stdio.h>
#include <algorithm>
using namespace std;
int par[100010],cost[100010],mx=999999,net[100010];
bool table[100010];
void makeset(int n)
{
    par[n]=n;
    table[n]=false;
    cost[n]=mx;
}
int find(int x)
{
   if(par[x]==x) return x;
   return par[x]=find(par[x]);
}
void Union(int a,int b)
{
    int u=find(a);
    int v=find(b);
    if(u!=v)
    {
        par[u]=v;
        //cost[u]=min(cost[u],cost[v]);
    }
}
int main()
{
    int n,m,x,y,i,a,b,j,c;
    for(;;)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        makeset(i);
        for(i=0;i<m;i++)
        {
        scanf("%d %d",&a,&b);
        Union(a,b);
        }
        for(i=1,j=-1;i<=n;i++)
        {
            if(table[par[i]]==false)
            {
                table[par[i]]=true;
                net[++j]=par[i];
            }
            scanf("%d",&c);
            if(c<0)
            continue;
            cost[par[i]]=min(c,cost[par[i]]);
        }
        int mn=mx,sum;
        if(j>0)
        {
            puts("0");
            return 0;
        }
        for(i=0;i<=j;i++)
        printf("%d ",net[i]);
        puts("re");
        for(i=0,sum=0;i<=j;i++)
        {
            //printf("%d ",net[i]);
            if(cost[net[i]]==mx)
            {
                puts("-1");
                return 0;
            }
            sum+=cost[net[i]];
            mn=min(mn,cost[net[i]]);
        }
        sum+=(j-1*mn);
        printf("%d\n",sum);
    }
return 0;
}
