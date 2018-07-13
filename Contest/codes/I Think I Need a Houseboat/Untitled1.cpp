#include <stdio.h>
#include <math.h>
double distance(float x1,float y1){

double dis;
dis=sqrt((x1*x1)+(y1*y1));
return dis;
}
int main ()
{
    int n,a,kase=1;
    double area=0.0,d,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf %lf",&x,&y);
        d=distance(x,y);
        //printf("%.9lf\n",d);
        area=1.0*acos(-1)*d*d;
        //printf("%.9lf\n",area);
        a=ceil(area/(1.0*100));
        printf("Property %d: This property will begin eroding in year %d.\n",kase++,a);
        if(n==0)
        printf("END OF OUTPUT.\n");
    }
    //printf("%.9lf",acos(-1));
    return 0;
}
