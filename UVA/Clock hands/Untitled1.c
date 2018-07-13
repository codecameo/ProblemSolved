#include <stdio.h>
int main ( )
{
int h,m;
float a,b,c,d,e,f;
while(scanf("%d:%d",&h,&m)!=EOF)
{
if(h==0 && m==0)
break;
a=((30*h)+(0.5*m));
b=(6*m);
c=a-b;
d=360-c;
e=(-c);
f=360+c;
if (c<=180)
{
if (c<0 && c>=(-180))
printf("%.3f\n",e);

else if (c<(-180))
printf("%.3f\n",f);

else
printf("%.3f\n",c);
}

else
printf("%.3f\n",d);
}
return 0;
}
