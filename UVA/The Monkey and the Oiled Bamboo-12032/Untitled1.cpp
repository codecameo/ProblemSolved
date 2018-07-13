#include <stdio.h>
#include <algorithm>
using namespace std;
int num[1000000];
int main()
{
    int tcase,i,j,n,max,c,cas=1;
    scanf("%d",&tcase);
    while(tcase--)
    {
      scanf("%d",&n);
      num[0]=0;
      for(i=1,max=-1;i<=n;i++)
      {
          scanf("%d",&num[i]);
      }
      for(i=n,max=-1;i>0;i--)
      {
           c=num[i]-num[i-1];
            if(c>max)
            max=c;
            else if(c==max)
            max++;
      }

        printf("Case %d: %d\n",cas,max);
        cas++;
    }
    return 0;
}
