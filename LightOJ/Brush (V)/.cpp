#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf=3746527675;
int main()
{
    int t,node,edge,i,kase=1,x,y,w,j,k;
    int d[101][101];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&node,&edge);
        memset(d,inf,sizeof(d));
        for(i=0;i<edge;i++)
        {
            scanf("%d %d %d",&x,&y,&w);
            d[y][x]=min(d[y][x],w);
            d[x][y]=min(d[x][y],w);
        }
        for(k=0;k<node;k++)
        for(i=0;i<node;i++)
        for(j=0;j<node;j++)
        if(d[i][j]>d[i][k]+d[k][j])
        d[i][j]=d[i][k]+d[k][j];
        printf("Case %d: ",kase++);
            if(d[node-1]==inf)
            puts("Impossible");
            else
            printf("%d\n",d[node-1]);

    }
    return 0;
}


