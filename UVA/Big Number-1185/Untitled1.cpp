#include <stdio.h>
int fact(int a)
{
    long long int i,pro=1;
    for(i=1;i<=a;i++)
    {
        pro*=i;
    }
    return pro;
}
int main ()
{
    long long int n,k=0,c,i,a,j;
    while(scanf("%lld",&n)!=EOF)
    {
       for(j=0;j<n;j++)
        {
        scanf("%lld",&a);
        c=fact(a);
        printf("%lld\n",c);
        for(i=c;i>=1;i/=10)
        {
            k++;
        }
        printf("%lld\n",k);
        k=0;
        }
    }
    return 0;
}
