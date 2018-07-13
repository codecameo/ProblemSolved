#include <stdio.h>
#include <queue>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int d[10000000],count;
vector<int>g[1000000];
map<long long,int>visit;
queue<int>q;
/*int bfs(int s,int lim){
int u,v;
queue<int>q;
count=0;
memset(d,0x3F,sizeof(d));
memset(visit,0,sizeof(visit));
d[s]=0;
visit[s]=1;
q.push(s);
while(!q.empty()){
u=q.front();
q.pop();
for(v=0;v<g[u].size();v++){
if(visit[g[u][v]]!=1){
q.push(g[u][v]);
d[g[u][v]]=d[u]+1;
visit[g[u][v]]=1;
if(d[g[u][v]]>lim)
return 0;
count++;
//cout<<g[u][v]<<endl;
}
}
}
return 0;
}*/
int main(){
int tcase,to,from,st,tl,i,j,kase=0,nd[100000],node,u,v;
for(;;){
cin>>tcase;
memset(nd,0,sizeof(nd));
node=0;
memset(g,0,sizeof(g));
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
//memset(d,0x3F,sizeof(d));
visit.clear();
d[st]=0;
visit[st]=1;
q.push(st);
//printf("g\n");
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
//cout<<g[u][v]<<endl;
}
}
}
printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++kase,node-count-1,st,tl);
}
}
return 0;
}
