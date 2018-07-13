#include <stdio.h>
#include <math.h>
int main ()
{
    int k,l,u,zap;
    for(k=0;;k++)
    {
        scanf("%d %d",&l,&u);
        if(l==-1 && u==-1)
        break;
        zap=fabs(l-u);
        if(zap>50)
        zap=100-zap;
        printf("%d\n",zap);
    }
    return 0;
}
