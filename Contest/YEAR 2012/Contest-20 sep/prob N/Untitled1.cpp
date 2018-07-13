#include <stdio.h>
#include <math.h>
#include <string.h>
long long int p[100000];
void fact()
{
long long int num,sum,x,i;
for(num=1;num<=1000;num++)
{
x=sqrt(num);
for(i=1,sum=0;i<=x;i++)
{
if(num%i==0)
{
sum=sum+i+(num/i);
if(i==(num/i))
sum-=i;
}
}
p[sum]=num;
}

}
int main()
{
long long int tcase,i,num,sum,x,kase=1;
memset(p,-1,sizeof(p));
for(i=0;;i++)
{
scanf("%lld",&num);
if(num==0)
break;
fact();
printf("Case %lld: %lld\n",kase,p[num]);
kase++;
}
return 0;
}
