#include <stdio.h>
#include <algorithm>
#define inf 9000000
using namespace std;
int ar[11][2001][1];
int main()
{
    int t,n,m,i,j,x;
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

        for(i=0;i<m;i++)
        {
            memset(fl,false,sizeof(bool)*m+1);
            for(j=0;j<n;j++)
            {
                fl1[ar[i][j]]=true;
            }
            for(j=0;j<n;j++){
                x=ar[i][j];
              if(fl[x]==false)
                  fl[x]=true;
              else
              {
                  for(k=1,step1=0,step2=0;;k++)
                  {
                      if(fl1[x+k]==true)
                          step1++;
                      else
                      break;
                      if(fl1[x-k]==true)
                          step2++;
                      else
                      break;
                  }
              }
            }
        }
    }
}
