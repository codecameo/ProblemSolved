#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define pi acos(-1)

using namespace std;

int main()
{
    int kase=1,t;
    double res,R,r,p,h,C_rate;
    char num[300];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf %lf",&R,&r,&h,&p);
        C_rate=(R-r)/h;
        R=R-C_rate*(h-p);
        res= (pi*p*(r*r+r*R+R*R))/3;
        printf("Case %d: ",kase++);
        printf("%.8lf\n",res);
    }

    return 0;
}

