#include <stdio.h>
int main ()
{
    long long int i,j,k=0,a,b,max=0,num[2];
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
    for(i=a;i<=b;i++)
    {
       for(j=i;j>=1;)
        {
            k++;
            if(j==1)
            break;
            if(j%2==0)
            j=j/2;
            else
            j=(3*j)+1;
        }
        if(max<k)max=k;
        k=0;
    }
    printf("%lld %lld %lld\n",a,b,max);
    max=0;
    }
    return 0;
}
