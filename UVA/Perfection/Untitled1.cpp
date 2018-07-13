#include <stdio.h>
#include <math.h>
int main ()
{
    int a,n,i,sum=1,c;
    while(scanf("%d",&n)!=EOF)
    {
        printf("PERFECTION OUTPUT\n");
        if(a==0)
        {
            printf("END OF OUTPUT\n");
        }
        a=sqrt(n);
        for(i=2,sum=1;i<=a;i++)
        {
           if(n%i==0)
           {
               c=n/i;
              // printf("%d %d ",i,c);
               sum=sum+i+c;
           }
        if(i==c)
        sum=sum-c;
        }
	//	printf("%d ",sum);
        if(sum==n)
        printf("%5d  PERFECT\n",n);
        else if(sum<n)
        printf("%5d  DEFICIENT\n",n);
        else if(sum>n)
        printf("%5d  ABUNDANT\n",n);
    }
    return 0;
}
