#include <stdio.h>
int main ()
{
    int lim,wav,i,j,k,p=0,kase;
    scanf("%d",&kase);
        while(kase--)
        {
        scanf("%d %d",&lim,&wav);
           for(k=1;k<=wav;k++)
           {
            for(i=1;i<=lim;i++)
            {
             for(j=1;j<=i;j++)
             {
                 printf("%d",i);
             }
            printf("\n");
            }
           for(i=lim-1;i>=1;i--)
            {
             for(j=1;j<=i;j++)
             {
                 printf("%d",i);
             }
            printf("\n");
            }
            if(k<wav)
            printf("\n");
           }
           if(kase>0)
           printf("\n");
        }
    return 0;
}
