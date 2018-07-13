#include <stdio.h>
#include <math.h>
#include <string.h>
int p[500010];
void divisor()
{
    memset(p,0,sizeof(p));
    int i,j;
    for(i=1;i<=500000;i++)
    {
        for(j=i;j<=500000;j+=i)
        p[j]+=i;
    }
}
int main ()
{
    int tcase,i,num;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&num);
        divisor();
        //for(i=0;i<=30;i++)
        //printf("%d ",p[i]);
      printf("%d\n",p[num]-num);
    }
    return 0;
}
