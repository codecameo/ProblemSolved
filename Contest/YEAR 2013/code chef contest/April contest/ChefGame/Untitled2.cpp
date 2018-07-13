#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
#define mem(x,y) memset(x,y,sizeof(x))
using namespace std;
struct data
{
    int u, v;
    double cost;
    bool operator <(const data &p)const{
        return cost>p.cost;
    }
};
struct co_ordinate
{
    int x;
    int y;
};
int par[506];
void inititialize(int n)
{
    for(int i=1;i<=n+1;i++)
    par[i]=i;
}
int findparent(int r)
{
    if(par[r]==r)  return r;
    return par[r]=findparent(par[r]);
}

bool isUnion(int r, int s)
{
    r=findparent(r);
    s=findparent(s);
    if(r==s) return true;
    return false;
}
void makeUnion(int r, int s)
{
    r=findparent(r);
    s=findparent(s);
    par[r]=s;
}
double dist(int x1, int y1, int x2, int y2)
{
    return sqrt((x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0);
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int s, p;
        cin>>s>>p;
        data g;
        mem(par,0);
        co_ordinate point[p+6];
        priority_queue<data>q;
        for(i=0;i<p;i++)
        {
            cin>>point[i].x>>point[i].y;
            for(j=0;j<i;j++)
            {
                double cos=dist(point[i].x,point[i].y,point[j].x,point[j].y);                g.u=i;
                g.v=j;
                g.cost=cos;
                q.push(g);
            }
        }
      /*   while(!q.empty())

{
    data s;
    s=q.top();
    q.pop();
      printf("%lf\n",s.cost);
}*/
       int d=0, td=p-s;
        double min=-1;
        inititialize(p);
        for(i=0;!q.empty() && d <p-s;i++)
        {
            g=q.top();
            q.pop();
            if(!isUnion(g.u,g.v))
            {
                d++;
                min=g.cost;
                makeUnion(g.u,g.v);
            }
        }
        printf("%.2lf\n",min);
    }
    return 0;
}
