#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf=999999999;
int main()
{
    int t,node,edge,i,kase=1,x,y,w,j,k,ans;
    int d[101][101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&node,&edge);
        for(i=0;i<=node;i++)
        {
            for(j=0;j<=node;j++)
            d[i][j]=inf;
            d[i][i]=0;
        }
        for(i=0;i<edge;i++)
        {
            scanf("%d %d",&x,&y);
            if(x!=y)
            d[y][x]=d[x][y]=1;
        }
        for(k=0;k<node;k++)
        for(i=0;i<node;i++)
        for(j=0;j<node;j++){
        if(d[i][j]>d[i][k]+d[k][j])
        d[j][i]=d[i][j]=d[i][k]+d[k][j];
        }
      scanf("%d %d",&x,&y);
      //printf("%d\n",d[x][y]);
      //int ans;
      ans=-1;
      for(i=0;i<=node;i++)
       d[i][i]=0;
      for(i=0;i<node;i++){
      ans=max(ans,d[x][i]+d[i][y]);
      }
        printf("Case %d: %d\n",kase++,ans);

    }
    return 0;
}
