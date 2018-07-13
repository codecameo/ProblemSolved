#include <stdio.h>
int main ()
{
    int a,n,i,sum,c,num[100000],j;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        for(i=1,j=0;i<n;i++)
        {
           if(n%i==0)
           {
             num[j]=i;
             j++;
           }
        }
        for(i=0,sum=0;i<j;i++)
        {
            sum+=num[i];
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

