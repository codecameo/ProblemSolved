#include <stdio.h>
#include <queue>
#include <stack>

using namespace std;
int main()
{
int type,val,n;
while(scanf("%d",&n)!=EOF)
{
bool st,qu,pqu;
st=qu=pqu=true;
queue<int> q;
priority_queue<int> pq;
stack<int> s;
for(int i=0;i<n;i++){
scanf("%d %d",&type,&val);
if(type==1)
{
q.push(val);
pq.push(val);
s.push(val);
}
else
{
if(!q.empty && qu==true)
{
if(val!=q.front)
qu=false;
q.pop();
}
if(!pq.empty && pqu==true)
{
if(val!=pq.top)
pqu=false;
pq.pop();
}
if(!s.empty && st==true)
{
if(val!=s.top)
st=false;
s.pop();
}
}
}
if(qu==false && pqu==false && st==false)
printf("impossible\n");
else if(qu==true && pqu==false && st==false)
printf("queue\n");
else if(qu==false && pqu==true && st==false)
printf("priority queue\n");
else if(qu==false && pqu==false && st==true)
printf("stack\n");
else
printf("not sure\n");
}
}
