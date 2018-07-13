#include <stdio.h>
#include <math.h>
int main()
{
    long long int a,f,k=1,i;
    double c;
    while(scanf("%lld",&a)!=EOF)
    {
        if(a==0)
        break;
        c=sqrt(9+(8*a));
        i=ceil((3+c)/2);
        printf("Case %lld: %lld\n",k,i);
        k++;
    }

    return 0;
}
