#include <stdio.h>
#include <math.h>
int main ()
{
    int tcase,num,i,count;
    float n,
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d",&num);
        for(i=2,count=0;i<=num/2;i++)
        {
            if(num%i==0)
            {
                n=(1.0*num/i);
                if(i%2!=0)
                count++;
                if(n%2==1 && i*2>n)
                count++;
                printf("%d %d %d\n",count,i,n);
            }
            else if(num%i==(i/2))
            {
                count++;
               printf("%d %d\n",i,count);
            }
        }
        printf("%d\n",count);
    }

}
