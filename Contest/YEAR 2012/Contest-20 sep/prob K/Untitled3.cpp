#include <stdio.h>
#include <math.h>
int isprime(long long x);

int isprime(long long in)
{
    if(in<0)
    {
        return 0;
    }

    long long i;

    for(i=2;i<in;i++)
    {
        if(in%i==0)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    long long in;
    long long i;

    printf("\nThis program finds the largest prime factor of a number.\n");
    printf("Enter a number to analyze: ");
    scanf("%lld", &in);

    for(i=in/2-1;i>1;i=i-2)
    {
        if(in%i==0)
        {
            if(isprime(i))
            {
                printf("%lld is the largest prime factor of %lld.", i, in);
                return 0;
            }
        }
    }
    return 0;
}
