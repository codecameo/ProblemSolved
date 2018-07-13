#include <stdio.h>
#include <math.h>
int main ()
{
    float p,a,c,d,r,b;
    while(scanf("%d %d",&r,&a)!=EOF)
    {
        //p=acos(-1);

        d=r*r*sin(2*3.1416*a);
        printf("%d\n",d);
    }

    return 0;
}
