#include <stdio.h>
int main ()
{
    int T,i,d;
    long long int C;
    double c,f,F;
    scanf("%d",&T);
for(i=1;i<=T;i++)
{
    if(T>100)
    continue;
    scanf("%lld %d",&C,&d);
    F=1.0*d*5/9;
   c=C+F;
   printf("Case %d: %.2lf\n",i,c);
}
return 0;

}

