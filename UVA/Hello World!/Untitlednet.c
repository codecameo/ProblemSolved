#include<stdio.h>
#include<math.h>
int main()
{
long int num,kase=1,i,ans;
while(scanf("%ld",&num)==1)
{
if(num<0) break;
for(i=0;;i++)
{
if(pow(2,i)>=num)
{
ans=i;
break;
}
}
printf("Case %ld: %ld\n",kase,ans);
kase++;
}
return 0;
}
