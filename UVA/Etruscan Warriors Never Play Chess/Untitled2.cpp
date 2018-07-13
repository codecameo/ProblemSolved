# include <stdio.h>
# include <math.h>
int main()
{
    long long i,n,t,s;
   scanf("%lld",&t);
   for(i=1;i<=t;i++)
   {
       scanf("%lld",&n);
       s=sqrt((n*8)+1)-1;
       s/=2;
       printf("%lld\n",s);
   }
    return 0;
}
