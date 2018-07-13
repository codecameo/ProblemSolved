#include <stdio.h>
#include <algorithm>
#include <string.h>
#define inf 9000000
using namespace std;
int ar[11][2001],num[2001],fl[2001],kase=1;
int main()
{
    int t,n,m,i,j,step,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++){
                //printf("%di %dj\n",i,j);
                scanf("%d",&ar[j][i]);
            }

        /*for(i=0;i<m;i++)
        sort(ar[i],ar[i]+n);*/

        for(i=0,step=0;i<m;i++)
        {
            for(j=0;j<=n;j++){
             fl[j]=false;
             num[j]=0;
            }
            for(j=0;j<n;j++)
            {
                num[ar[i][j]]++;
                fl[ar[i][j]]=true;
                //printf("%d %d %dnum\n",num[ar[i][j]],fl[ar[i][j]],ar[i][j]);
            }
            for(j=0;j<n;j++){
                //x=ar[i][j];
               if(fl[j]==false)
               {
                   for(k=1;;k++)
                   {
                       //printf("%d %d\n",j+k,j-k);
                       if(j-k<0 && j+k>=n)
                            break;
                       if(num[j-k]>1 && j-k>=0)
                       {
                           num[j-k]--;
                           step+=k;
                           //printf("%d\n",step);
                           fl[j]=true;
                           break;
                       }

                       else if(num[j+k]>1 && j+k<n)
                       {
                           num[j+k]--;
                           step+=k;
                           //printf("%d\n",step);
                           fl[j]=true;
                           break;
                       }
                   }
               }
            }
        }
        printf("Case %d: %d\n",kase++,step);
    }
    return 0;
}
