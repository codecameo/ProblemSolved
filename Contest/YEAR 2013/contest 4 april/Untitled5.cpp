#include <stdio.h>
#include <math.h>
double ds;
void dis(double x1,double x2,double y1,double y2)
{
    double d,x,y;
    x=(x1-x2)*(x1-x2);
    y=(y1-y2)*(y1-y2);
    d=sqrt(x+y);
    //printf("%lf\n",d);
    ds+=d;
}
int main()
{
    int n,i;
    double a,b,a1,b1,x1,y1,r;
    ds=0.0;
    while(scanf("%d",&n)!=EOF){
    scanf("%lf",&r);
    scanf("%lf %lf",&a,&b);
    a1=a;
    b1=b;
    for(i=1;i<n;i++)
    {
        scanf("%lf %lf",&x1,&y1);
        dis(a,x1,b,y1);
        a=x1;
        b=y1;
    }
    dis(a,a1,b,b1);
    ds+=(2.0*3.1416*r);
    printf("%.2lf\n",ds);
    }
}
