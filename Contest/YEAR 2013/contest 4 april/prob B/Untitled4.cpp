#include <stdio.h>
#include <set>
#include <string.h>
#define MAX 1002
using namespace std;
int px[]={1,-1,-1,-2,-2,-3};
int py[]={-2,-2,-3,1,-1,-1};
int table[MAX][MAX];
bool valid(int x,int y)
{
    if(x<0 || y<0)
    return false;
    return true;
}
int grundyNumber(int x,int y)
{
    int x1,y1,ret,i;
    if(table[x][y]!=-1)
    return table[x][y];
    set<int>s;
    for(i=0;i<6;i++)
    {
        x1=x+px[i];
        y1=y+py[i];
        if(valid(x1,y1))
        s.insert(grundyNumber(x1,y1)) ;
    }
    ret=0;
    while (s.find(ret)!=s.end())
    ret++;

    return table[x][y]=ret;
}
int main()
{
    int t,i,n,X,Y,j,kase=1,nim;
    memset(table,-1,sizeof(table));
    for(i=0;i<MAX;i++)
    for(j=0;j<MAX;j++)
     table[i][j]=grundyNumber(i,j);
    scanf("%d",&t);
    while(t--)
    {
        nim=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&X,&Y);
            nim=nim^table[X][Y];
        }
      printf("Case %d: ",kase++) ;
	  if(nim) printf("Alice\n") ;
	  else printf("Bob\n") ;

    }
    return 0;
}
