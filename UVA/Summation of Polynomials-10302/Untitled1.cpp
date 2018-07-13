#include <stdio.h>
int main ()
{
    long long int c,n;
    while(scanf("%lld",&n)!=EOF)
    {
    c=n*n*(n+1)*(n+1)/4;
    printf("%lld\n",c);
    }
return 0;
}
