# include <stdio.h>
int main ()
{
long long int a,i,b,j,k,l,m,sum,num[100];
for(m=0;;m++)
{
    scanf("%lld",&a);
    if(a==0)
    break;
for(i=0,j=1,k=1,l=0;k<=a;i=j,j=sum,k++)
   sum=i+j;
   printf("%lld\n",sum);
}
return 0;
}
