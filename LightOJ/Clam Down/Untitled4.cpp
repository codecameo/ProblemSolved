#include <stdio.h>
#include <math.h>
int main()
{
    int t,kase=1,n;
    double ans,ang,R;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %d",&R,&n);
        ang=acos(-1)/(1.0*n);
        ans=1.0*R*sin(ang)/(sin(ang)+1.0);
        printf("Case %d: %.10lf\n",kase++,ans);
    }
return 0;
}
