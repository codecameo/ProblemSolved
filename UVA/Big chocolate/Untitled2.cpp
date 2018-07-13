#include <stdio.h>
int main ()
{
    int a,b,c,d,r;
    while(scanf("%d %d",&r,&c)!=EOF)
    {
        a=r-1;
        b=c-1;
        d=a+(r*b);
        printf("%d\n",d);
    }

    return 0;
}
