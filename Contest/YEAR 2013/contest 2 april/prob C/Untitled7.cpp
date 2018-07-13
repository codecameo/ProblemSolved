#include <stdio.h>
#include <algorithm>
#include <string.h>
#define inf 9000000
using namespace std;
int ar[11][2001],num[2001],fl[2001],kase=0;
int main()
{
    int t,n,m,i,j,x,step,k;
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
            memset(fl,false,sizeof(bool)*m+1);
            memset(num,0,sizeof(num));
            for(j=0;j<n;j++)
            {
                num[ar[i][j]]++;
                fl[ar[i][j]]=true;
                //printf("%d %d %dnum\n",num[ar[i][j]],fl[ar[i][j]],ar[i][j]);
            }
            for(j=0;j<n;j++){
                x=ar[i][j];
               if(fl[j]==false)
               {
                   for(k=1;;k++)
                   {
                       if(x-k<0 && x+k>=n)
                            break;
                       if(num[x-k]>1 && x-k>=0)
                       {
                           num[x-k]--;
                           step+=k;
                           printf("%d\n",step);
                           fl[j]=true;
                           break;
                       }

                       else if(num[x+k]>1 && x+k<n)
                       {
                           num[x+k]--;
                           step+=k;
                           printf("%d\n",step);
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
