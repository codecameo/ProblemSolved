#include <stdio.h>
int main ()
{
    int n,a,i,c,b,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        b=((((a*567)/9+7492)*235)/47)-498;
        if(b<0)
        b=-1*b;
        c=(b%100);
        d=(c/10);
        printf("%d\n",d);
    }

    return 0;
}
