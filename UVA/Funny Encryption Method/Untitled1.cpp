#include <stdio.h>

long long int digit(long long int N)
{
    long long int i,j,b,num1=0;
    for(i=N,num1=0;i>0;i=i/2)
    {
     b=(i%2);
     if(b==1)
     num1++;
    }
    return num1;
}
int main ()
{
    long long int n,b=0,i,a,j,d=0,c,rem;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a);
        b=digit(a);
        for(j=a,d=0;j>0;j/=10)
        {
            rem=j%10;
            c=digit(rem);
            d=d+c;
        }
       printf("%lld %lld\n",b,d);
        d=0;
    }
    return 0;
}
