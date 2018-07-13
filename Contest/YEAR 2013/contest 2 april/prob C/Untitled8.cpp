#include <stdio.h>
#include <algorithm>
#include <string.h>
#define inf 9000000
using namespace std;
int ar[11][2001];
int main()
{
    int t,n,m,i,j,x,step,k,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        step=0;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                //printf("%di %dj\n",i,j);
                scanf("%d",&ar[j][i]);
            }

        for(i=0;i<m;i++)
        sort(ar[i],ar[i]+n);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                step+=abs(ar[i][j]-j);
            }
        }
        printf("Case %d: %d\n",kase++,step);
    }
    return 0;
}
