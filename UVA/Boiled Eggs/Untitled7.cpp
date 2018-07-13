#include <stdio.h>
int main ()
{
  int k,sum=0,tcase=0,i,num[35],n,p,q;
  scanf("%d",&k);
  while(k--)
  {
      scanf("%d %d %d",&n,&p,&q);
      for(i=0;i<n;i++)
      scanf("%d",&num[i]);
      for(i=0,sum=0;i<n;i++)
     {
         if(i==p || sum+num[i]>q) break;
         else sum+=num[i];
     }
      tcase++;
      printf("Case %d: %d\n",tcase,i);
  }
return 0;
}
