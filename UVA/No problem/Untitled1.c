#include <stdio.h>
int main ()
{
    int num1[100],num2[100],i,j,a,b,S,k,sum;

   for(k=1;;k++)
   {
    scanf("%d",&S);
       if(S<0 || S>100)
       break;
        num1[0]=S;
     for(i=1;i<=12;i++)
    {
        scanf("%d",&a);
        if(a>=0 && a<=20)
        num1[i]=a;
    }
    for(j=0;j<12;j++)
    {
        scanf("%d",&b);
        if(b>=0 && b<=20)
        num2[j]=b;
    }
    printf("Case %d:\n",k);
    sum=num1[0];
    for(i=1,j=0;j<12;j++,i++)
    {
        if(sum<num2[j])
        printf("No problem. :(\n");
        if(sum>=num2[j])
        {
           printf("No problem! :D\n");
           sum=sum-num2[j];
        }
        sum=sum+num1[i];
    }}

    return 0;
}
