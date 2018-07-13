#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int tcase,a[3],lcm,n,m,l,i,x,d,c=0,kase=1;
    scanf("%lld",&tcase);
    while(tcase--)
    {
        scanf("%lld %lld %lld",&a[0],&a[1],&lcm);
        sort(a,a+2);
        n=a[0];
        m=a[1];
        //printf("%lld %lld\n",m,a[1]);
        l=lcm;
       // x=sqrt(n);
       if(l%n!=0 || l%m!=0)
        {
            printf("Case %lld: impossible\n",kase);
            continue;
        }
        i=2;
        while(i<=a[0])
        {
            if(n%i==0)
            {
                if(m%i==0)
                {
                    n/=i;
                    m/=i;
                    l/=i;
                }
                else
                i++;
                //printf("%lld %lld %lld\n",n,m,l);
                /*d=n/i;
                if(d!=i)
                if(m%i==0)
                {
                    n/=d;
                    m/=d;
                    l/=d;
                }*/
               //printf("%lld %lld %lld\n",n,m,l);
                if(n==1)
                break;
            }
            else
            i++;
            //printf("%lldi\n",i);
        }
        c=(l/n);
        c/=m;
        if(c==a[0] || c==a[1])
        c=lcm;
        printf("Case %lld: %lld\n",kase,c);
      kase++;

    }
    return 0;
}
