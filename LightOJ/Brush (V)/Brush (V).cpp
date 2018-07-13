#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf=37467;
int main()
{
    int t,node,edge,i,kase=1,x,y,w,j,k;
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
            scanf("%d %d %d",&x,&y,&w);
            d[y][x]=d[x][y]=min(d[x][y],w);
        }
        for(k=1;k<=node;k++)
        for(i=1;i<=node;i++)
        for(j=1;j<=node;j++){
        if(d[i][j]>d[i][k]+d[k][j])
        d[i][j]=d[i][k]+d[k][j];
        }

        printf("Case %d: ",kase++);
            if(d[1][node]==inf)
            puts("Impossible");
            else
            printf("%d\n",d[1][node]);

    }
    return 0;
}


