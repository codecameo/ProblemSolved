#include <stdio.h>
#include <math.h>
int main ()
{
    int n,kase=0,m,m1,m2,m3,m4,c;
    double a;
    scanf("%d",&n);
    while(n--)
    {
        kase++;
        scanf("%d",&m);
        if(m<=180000)
        {
            printf("Case %d: 0\n",kase);
            continue;
        }
        else if(m>180000 && m<=480000)
         {
             a=(m-180000)*.10;
             c=ceil(a);
             if(c<2000)
             printf("Case %d: 2000\n",kase);
			 else
             printf("Case %d: %d\n",kase,c);
             continue;
         }
        else if(m>480000 && m<=880000)
         {
             a=((m-480000)*.15)+30000;
             c=ceil(a);
             printf("Case %d: %d\n",kase,c);
             continue;
         }
         else if(m>880000 && m<=1180000)
         {
             a=((m-880000)*.20)+90000;
             c=ceil(a);
             printf("Case %d: %d\n",kase,c);
             continue;
         }
         else if(m>1180000)
         {
             a=((m-1180000)*.25)+150000;
             c=ceil(a);
             printf("Case %d: %d\n",kase,c);
             continue;
         }
    }
    return 0;
}
