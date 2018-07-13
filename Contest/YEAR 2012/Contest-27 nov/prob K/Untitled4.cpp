#include<stdio.h>
#define min(x,y) (((x)<(y))?(x):(y))
long long sqrt(long long a)
{
    long long s=0,t=min(a,100000000),h;
    while (s<t)
    {
        h=(s+t+1)>>1;
        if (h*h>=a)
            t=h-1;
        else
            s=h;
    }
    return s;
}


int main()
{
    long long T,Ts,j,k,n,m,s,t;
    scanf("%lld",&T);
    for (Ts=1;Ts<=T;Ts++)
    {
        scanf("%lld",&n);
        s=t=(m=sqrt(n))+1;
        k=(s*s-m*m)/2+m*m+1;
        j=n-k;
        if (m&1)
        {
            if (j>0)
                t-=j;
            else
                s+=j;
        }
        else
        {
            if (j>0)
                s-=j;
            else
                t+=j;
        }

        printf("Case %lld: %lld %lld\n",Ts,s,t);
    }
    return 0;
}
