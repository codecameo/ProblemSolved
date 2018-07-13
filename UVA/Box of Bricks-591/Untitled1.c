#include <stdio.h>
int main ()
{
    long long int n,i,j,ar[100000],avg,sum,sum1,b,k;
    for(k=1;;k++)
    {
    scanf("%lld",&n);
    if(n==0)
    break;
    sum=0;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&ar[i]);
        sum=sum+ar[i];
    }
    avg=sum/n;
    sum1=0;
    for(i=0;i<n;i++)
    {
        if(avg<ar[i])
        {
        b=ar[i]-avg;
        sum1=sum1+b;
        }

    }
    printf("Set #%lld\nThe minimum number of moves is %lld.\n\n",k,sum1);
    }

    return 0;
}
