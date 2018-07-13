#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
int T;
scanf("%d",&T);
while(T--)
{
int n;
scanf("%d",&n);
int x=sqrt(n);
long long int sum=0;
for(int i=2;i<=x;i++)
if(n%i==0) sum+=(i+n/i);
if(x*x==n) sum-=x;
printf("%lld\n",sum+1);
}
}
