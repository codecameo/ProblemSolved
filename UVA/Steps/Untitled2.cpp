#include <stdio.h>
int main ()
{
    int tcase,i,j,k,a,b,count=0;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d",&a,&b);
        for(i=a,j=b,k=1,count=0;i<j;k++)
        {
            i=i+k;
             if(j<=i)
             {
              count++;
              break;
             }
            else
           {
               j=j-k;
                count+=2;
           }
        }
        printf("%d\n",count);
    }
    return 0;
}
