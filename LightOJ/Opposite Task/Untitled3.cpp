#include <stdio.h>
int main()
{
    int t,b,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&b);
        a=b/2;
        printf("%d %d\n",a,b-a);
    }
    return 0;
}

