#include <stdio.h>
int main ()
{
    long long int s,d,i,sum=0;
    while(scanf("%lld %lld",&s,&d)!=EOF)
    {
        for(i=s;;i++)
        {
            sum+=i;
            if(sum>=d)
            break;
        }
        printf("%lld\n",i);
        sum=0;
    }


    return 0;
}
