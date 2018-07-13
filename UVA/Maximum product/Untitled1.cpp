#include <stdio.h>
int main ()
{
long long int pro,k=1,i,j,n,num[20],max;
while(scanf("%lld",&n)==1)
{
for(i=0;i<n;i++)scanf("%lld",&num[i]);
for(i=0,max=0;i<n;i++)
{
for(j=i,pro=1;j<n;j++)
{
pro*=num[j];
if(max<pro)max=pro;
}
}
printf("Case #%lld: The maximum product is %lld.\n\n",k,max);
k++;
}
return 0;
}
