#include <stdio.h>
int main ()
{
    int a,b,i,sum,k,n;
    scanf("%d",&n);
    for(k=1;k<=n;k++)
   {
    scanf("%d %d",&a,&b);
    sum=0;
    for(i=a;i<=b;i++)
    {
        if(i%2==1)
        sum=sum+i;
    }
    printf("Case %d: %d\n",k,sum);
   }
    return 0;
}

