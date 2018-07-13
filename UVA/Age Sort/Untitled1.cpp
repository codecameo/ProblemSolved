#include <stdio.h>
int main ()
{
    int num[105]={0},n,i,j,k,a;
    for(i=0;;i++)
    {
    scanf("%d",&n);
    for(j=0;j<n;j++)
        {
          scanf("%d",&a);
          num[a]++;
        }
     for(j=0;j<105;j++)
     if(num[j]>0)
     for(k=0;k<num[a];k++)
     {
         printf("%d ",j);
     }
    }
return 0;
}
