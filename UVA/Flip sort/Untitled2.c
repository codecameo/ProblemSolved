#include <stdio.h>
int gcd(long long int a, long long int b)
{
long long int gcd(int j,int i)
{
if(i==0) return j;
return gcd(i,j%i);
}
}

int main ()
{
    long long int c,G,j,l,k;
    while(scanf("%lld",&c)!=EOF)
    {
    if(c==0)
    break;
    G=0;
    for(j=1;j<c;j++)
    {
    for(k=j+1;k<=c;k++)
    {
        G+=gcd(j,k);

    }
    }
    printf("%lld\n",G);
    }
    return 0;
}
