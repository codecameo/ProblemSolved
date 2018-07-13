#include <stdio.h>
int main ()
{
    int n,m,k,c;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d",&m,&n);
        c=(m/3)*(n/3);
        printf("%d\n",c);
    }

    return 0;
}
