#include<stdio.h>
int main()
{
long int num,half,total;
while(scanf("%ld",&num)==1)
{
half=num/2;
total=num+half;
printf("%ld\n",total);
}
return 0;
}
