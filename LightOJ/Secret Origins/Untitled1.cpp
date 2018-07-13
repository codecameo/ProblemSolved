#include <stdio.h>
int main()
{
    int t,kase=1;
    long long int n,m,c,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        m=__builtin_popcountll(n);
       //printf("%lld\n",m);
        for(i=n+1;;i++)
        {
            c=__builtin_popcountll(i);
            if(c==m)
            {
                printf("Case %d: %lld\n",kase++,i);
                break;
            }
        }
    }
    return 0;
}
