#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;
//int vis[1000000010];
map<long long int,int>m;
struct song{
long long int b,l;
}sg[100010];
bool compare(song x,song y)
{
  return x.l<y.l;
}

int main()
{
    int t,i,n,count,band;
    long long int swt;
    scanf("%d",&t);
    while(t--)
    {
        //memset(vis,0,sizeof(vis));
        m.clear();
        scanf("%d",&n);
        for(i=0,count=0;i<n;i++){
            scanf("%lld %lld",&sg[i].b,&sg[i].l);
            if(m[sg[i].b]==0)
            {
                count++;
                m[sg[i].b]=1;
            }
        }
       // printf("count-> %d\n",count);
        sort(sg,sg+n,compare);
        /*for(i=0;i<n;i++)
        {
            printf("%lld %lld\n",sg[i].b,sg[i].l);
        }*/
        for(i=0,swt=0,band=0;i<n;i++)
        {
           if(m[sg[i].b]==1)
           {
               band++;
               m[sg[i].b]=2;
               swt+=band*sg[i].l;
               //printf("band-> %d\n",band);
           }
           else
           swt+=sg[i].l*count;
          // printf("swt-> %d\n",swt);
        }
        printf("%lld\n",swt);

    }
}
