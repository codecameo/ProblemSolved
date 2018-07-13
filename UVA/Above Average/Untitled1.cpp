#include <stdio.h>
int main()
{
    long long int num[10000],i,count=0,sum=0,k,n;
    double per,avg;
    scanf("%lld",&k);
    while(k--)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&num[i]);
            sum+=num[i];
        }
        avg=sum/n;
        for(i=0;i<n;i++)
        {
            if(num[i]>avg)
            count++;
        }
        per=1.0*(count*100)/n;
        printf("%.3lf%%\n",per);
        count=0;sum=0;
    }
return 0;
}
