#include <stdio.h>
int main ()
{
    int T,i,a,b,c;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<b && b<c)
        printf("Case %d: %d\n",i,b);
        if(c<b && b<a)
        printf("Case %d: %d\n",i,b);
        if(a<c && c<b)
        printf("Case %d: %d\n",i,c);
        if(b<c && c<a)
        printf("Case %d: %d\n",i,c);
        if(b<a && a<c)
        printf("Case %d: %d\n",i,a);
        if(c<a && a<b)
        printf("Case %d: %d\n",i,a);
    }

    return 0;
}
