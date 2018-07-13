#include <stdio.h>
#include <math.h>
int i=1;
void w(double u1,double v1,double t1)
{
    double a1=0,s1=0;
    a1=(v1-u1)/t1;
    s1=((v1+u1)/2)*t1;
    printf("Case %d: %.3lf %.3lf\n",i,s1,a1);
}

void x(double u2,double v2,double a2)
{
  double s2,t2;
  t2=(v2-u2)/a2;
  s2=((v2+u2)/2)*t2;
  printf("Case %d: %.3lf %.3lf\n",i,s2,t2);
}

void y(double u3,double a3,double s3)
{
   double v3,t3;
   v3=sqrt((u3*u3)+(2*a3*s3));
   t3=(v3-u3)/a3;
   printf("Case %d: %.3lf %.3lf\n",i,v3,t3);
}

void z(double v4,double a4,double s4)
{
   double u4,t4;
   u4=sqrt((v4*v4)-(2*a4*s4));
   t4=(v4-u4)/a4;
   printf("Case %d: %.3lf %.3lf\n",i,u4,t4);
}
int main ()
{
    int m;
    double a,b,c;
    for(i=1;;i++)
    {
    scanf("%d %lf %lf %lf",&m,&a,&b,&c);
    if(m==0)
    break;
    else if(m==1)
    w(a,b,c);
    else if(m==2)
    x(a,b,c);
    else if(m==3)
    y(a,b,c);
    else if(m==4)
    z(a,b,c);
    }
    return 0;
}
