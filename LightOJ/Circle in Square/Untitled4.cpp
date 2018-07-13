#include <stdio.h>
#include <math.h>
double pi()
{
    return 2.0*acos(0.0);
}
int main()
{
    double red,square,circle;
    int t,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&red);
        circle=pi()*red*red;
        square=4.0*red*red;
        printf("Case %d: %.2lf\n",kase++,square-circle);
    }
}
