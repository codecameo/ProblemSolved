#include<stdio.h>
int main()
{
long long int i,j,k,n,num[20],max,pro,kase=1;
while(scanf("%lld",&n)==1)
{
for(i=0;i<n;i++)scanf("%lld",&num[i]);
for(i=0,max=0;i<n;i++)
{
for(j=i,pro=1;j<n;j++)
{
pro*=num[j];
if(pro>max)max=pro;
}
}
printf("Case #%lld: The maximum product is %lld.\n\n",kase,max);
kase++;
}
return 0;
}
