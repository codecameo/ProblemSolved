#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define Clear(a) memset(a,0,sizeof(a))

int parent[10000];
struct edge{
    int x,y,val;
   bool operator < ( const edge &p ) const
    {
        return val < p.val;
    }
};
vector<edge>gp;
void reset(int n)
{
    Clear(parent);
    gp.clear();
    for(int i=1;i<=n;i++)
    parent[i]=i;
}
int find(int x){
if(parent[x]==x) return x;
return parent[x]=find(parent[x]);
}
int final(int p,int r){
int x,y,i,total=0;
sort(gp.begin(),gp.end());
for(i=0,total=0;i<r;i++)
{
    x=find(gp[i].x);
    y=find(gp[i].y);
    if(x!=y){
    total+=gp[i].val;
    parent[x]=parent[y];
    }
}
return total;
}
int main (){
int p,r,x,y,val,i;
edge node;
while(scanf("%d",&p) &&p){
cin>>r;
reset(p);
for(i=0;i<r;i++){
cin>>x>>y>>val;
node.x=x;
node.y=y;
node.val=val;
gp.push_back(node);
}
printf("%d\n",final(p,r));
}
return 0;
}


