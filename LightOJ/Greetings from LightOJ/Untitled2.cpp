#include <stdio.h>
int main()
{
    int t,kase=1,a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",kase++,a+b);
    }
    return 0;
}
