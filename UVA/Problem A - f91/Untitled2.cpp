#include <stdio.h>
int main ()
{
    long long int n,s;
    while(scanf("%lld",&s)!=EOF)
    {
        if(s==0)
        break;
        n=s;
        if(n>=101)
        n=n-10;
        else
        n=91;
        printf("f91(%lld) = %lld\n",s,n);

    }


    return 0;
}
