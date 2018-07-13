#include <stdio.h>
#include <string.h>
int main()
{
    char s[6];
    long long int t,kase=1,m,n,ans=0,i;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        ans=__builtin_popcountll(n);
        if(ans%2==0)
        strcpy(s,"even");
        else
         strcpy(s,"odd");
        printf("Case %lld: %s\n",kase++,s);
    }
    return 0;
}
