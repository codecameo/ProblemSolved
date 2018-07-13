#include <stdio.h>
int main ()
{
    int k,l,w,h,tcase=1;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d %d %d",&l,&w,&h);
        if(l>20 || h>20 || w>20)
        printf("Case %d: bad\n",tcase);
        else
        printf("Case %d: good\n",tcase);
        tcase++;
    }
    return 0;
}
