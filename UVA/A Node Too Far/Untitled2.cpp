#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int count;
vector<int>g[1000000];
map<long long,int>visit,nd,d;
queue<int>q;
int main(){
int tcase,to,from,st,tl,i,j,kase=0,node,u,v;

while(cin>>tcase){
nd.clear();
node=0;
d.clear();
for(i=0;i<99900;i++)
g[i].clear();
if(tcase==0)
break;
while(tcase--){
cin>>to>>from;
g[to].push_back(from);
if(nd[to]!=1){
nd[to]=1;
node++;
}
g[from].push_back(to);
if(nd[from]!=1){
nd[from]=1;
node++;
}
}
for(;;){
cin>>st>>tl;
if(st==0 && tl==0)
break;
count=0;
visit.clear();
d[st]=0;
visit[st]=1;
q.push(st);
while(!q.empty()){
u=q.front();
q.pop();
for(v=0;v<g[u].size();v++){
if(visit[g[u][v]]!=1){
q.push(g[u][v]);
d[g[u][v]]=d[u]+1;
visit[g[u][v]]=1;
if(d[g[u][v]]>tl)
break;
count++;
}
}
}
printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++kase,node-count-1,st,tl);
}
}
return 0;
}
