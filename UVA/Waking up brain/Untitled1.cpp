#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#define pb push_back
#include <queue>
using namespace std;
int main()
{
    queue<char> q;
    map<char,int> m;
    char act[10],link[3];
    std::vector <int> ch[30];
    int i,j,node,edge,count,y;
    while(scanf("%d %d",&node,&edge)==2){
    for(i=1;i<=node;i++)
    ch[i].clear();
    m.clear();
    getchar();
    gets(act);
    y=strlen(act);
    for(i=0,j=1;i<edge;i++)
    {
        gets(link);
        if(m[link[0]]==0){
        ch[j++].pb(link[0]);
        ch[j-1].pb(link[1]);
        m[link[0]]=j-1;
        }
        else
        ch[m[link[0]]].pb(link[1]);
        if(m[link[1]]==0){
        ch[j++].pb(link[1]);
        ch[j-1].pb(link[0]);
        m[link[1]]=j-1;
        }
        else
        ch[m[link[1]]].pb(link[0]);
    }
    m.clear();
    for(i=0;i<strlen(act);i++)
    {
        m[act[i]]=1;
    }
    int year;
    for(year=0;;year++)
    {
    for(i=1;i<=node;i++)
     {
         if(m[ch[i][0]]==1)
         continue;
        for(j=1,count=0;j<ch[i].size();j++)
        {
            if(m[ch[i][j]]==1)
            count++;
        }
        if(count>2){
        q.push(ch[i][0]);
        y++;
        }
     }
     if(q.empty())
     break;
     else{
        while(!q.empty()){
      m[q.front()]=1;
      q.pop();
        }
     }
    }
    if(y==node)
    printf("WAKE UP IN, %d, YEARS\n",year);
    else
    puts("THIS BRAIN NEVER WAKES UP");
    }
    return 0;
}
