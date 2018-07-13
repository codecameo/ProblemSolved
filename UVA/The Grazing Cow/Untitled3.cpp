#include<stdio.h>
#include<math.h>

int main()
{
double a,b,l,d,pi=2*acos(0);
int n;
scanf("%d",&n);
while(n--)
{

scanf("%lf%lf",&d,&l);
a=l/2;
b=sqrt((l/2*l/2)-(d/2*d/2));
printf("%.3lf\n",pi*a*b);
}
return 0;
}
