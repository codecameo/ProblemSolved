#include <stdio.h>
long long int g;
long long int gcd(long long int a,long long int b)
{
long long int i;
for(i=1;i<=a || i<=b;i++)
{
    if(a%i==0 && b%i==0)
    g=i;
}
return g;
}
int main ()
{
    long long int n,m,i,j,k,c,a,e,l=0;
    scanf("%lld",&a);
    for(k=0;k<a;k++)
    {
      while(scanf("%lld %lld",&n,&m)!=EOF)
      {
      c=n*m;
    for(i=n;i<=m;i++)
    {
    for(j=n;j<=m;j++)

        if(c==(j*i))
        {
           break;
        }
        e=gcd(i,j);
        if(c==(j*i) && n==e)
        {
        printf("%lld %lld\n",i,j);
        l=0;
        break;
        }
        else if(i==m)
        printf("-1\n");
    }
    }
    }
    return 0;
}
