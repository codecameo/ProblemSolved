#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
#define MAX 10010
using namespace std;
vector< int > G[MAX];
std::pair <int,int> fo1,fo2;
map<pair<int,int>,bool> mymap;
int count,m,n;
void reset()
{
    int i;
    mymap.clear();
	for(i=0;i<=n+1;i++)
	G[i].clear();
	count=0;
}
void get_input()
{
    scanf("%d %d",&n,&m);
    int i,a,b;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        fo1 = std::make_pair (b,a);
        fo2 = std::make_pair (a,b);
        if(mymap[fo1]==true || mymap[fo2]==true)
        continue;
        else
        {
            mymap[fo1]=true;
            mymap[fo2]=true;
        }
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
int main()
{
	int t,kase=1,i,a,b;
	scanf("%d",&t);
	while(t--)
	{
		reset();
		//scanf("%d %d",&n,&m);
        get_input();
		//dfs(0,-1);
		count=0;
		for(i=0;i<n;i++)
		{
		    if(G[i].size()<2)
		    count++;
		}
		if(count>1)
		count--;
		printf("Case %d: %d\n",kase++,count);
	}
}
