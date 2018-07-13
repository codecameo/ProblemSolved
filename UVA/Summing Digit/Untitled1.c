#include <stdio.h>
int main ()
{
    int n,i,j,k,a,sum;
  while( scanf("%d",&n)==1)
   {
       if(n<=9 && n>0)
       printf("%d\n",n);

    else if(n==0)
    break;
    else if(n>=10)
    {
        for(i=n;i>=10;i=sum)
    {
        sum=0;
        for(j=i;j>0;j=j/10)
        {
           a=j%10;
           sum=sum+a;
        }
    }
    printf("%d\n",sum);
}}

    return 0;
}
