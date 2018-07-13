#include <stdio.h>
#include <math.h>
int main()
{
    long long int t,kase=1,m,n,w,num,i;
    scanf("%lld",&t);
    bool flag;
    while(t--)
    {
        flag=0;
        scanf("%lld",&w);
        n=1;
        while(1)
        {
            if(w%2==1)
            break;
            flag=1;
            n*=2;
            w/=2;
            m=w;
        }
        printf("Case %lld: ",kase++);
        if(flag==0)
        puts("Impossible");
        else
        printf("%lld %lld\n",m,n);
    }
    return 0;
}

