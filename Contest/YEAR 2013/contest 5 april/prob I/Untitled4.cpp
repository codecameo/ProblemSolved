#include <stdio.h>
int main()
{
    int t,i,j,r,c,nim,a,kase=1,x;
    scanf("%d",&t);
    while(t--)
    {
        nim=0;
        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
        {
            x=0;
            for(j=0;j<c;j++){
                scanf("%d",&a);
                x+=a;
            }
            nim=nim^x;
        }
        if (nim)
            printf("Case %d: Alice\n",kase++);
        else
            printf("Case %d: Bob\n",kase++);
    }
    return 0;
}
