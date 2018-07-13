#include <stdio.h>
#include <math.h>
int main()
{
    int t,kase=1,m,n,w,num,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&w);
        num=sqrt(w);
        n=-1;
        for(i=2;i<=num;i++)
        {
            if(w%i==0)
            {
                if(i%2==0)
                {
                    n=i;
                    m=w/n;
                }
                else
                {
                    m=i;
                    n=w/m;
                    break;
                }
            }
         }
         printf("Case %d: ",kase++);
         if(n==-1)
         puts("Impossible");
         else
         printf("%d %d\n",m,n);
    }
    return 0;
}
