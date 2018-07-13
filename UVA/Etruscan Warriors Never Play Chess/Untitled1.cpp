#include <stdio.h>
int main ()
{
    long long int n,a,i,sum=0,count;
    while(scanf("%lld",&n)!=EOF)
    while(n--)
    {
        scanf("%lld",&a);
        for(i=1,count=0;;i++)
        {
            sum+=i;
            if(sum>a)
            break;
            count++;
        }
        printf("%lld\n",count);
        sum=0;
    }

    return 0;
}

