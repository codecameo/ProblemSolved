#include <stdio.h>
int main ()
{
    int N,i,e,f,c,a,b,d,sum;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        scanf("%d %d %d",&e,&f,&c);
        a=e+f;
        sum=0;
        for(;a>c;e=b,f=d)
        {
            a=e+f;
            b=a/c;
            sum=sum+b;
            d=a%c;
        }
        printf("%d\n",sum);

    }

    return 0;
}
