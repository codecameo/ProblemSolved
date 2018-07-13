#include <stdio.h>
void digit(long long int N)
{
    long long int i,j,b,num1=0,ar[100000];
    printf("The parity of ");
    for(i=N,num1=0,j=0;i>0;i=i/2,j++)
    {
     b=(i%2);
     ar[j]=b;
     if(b==1)
     num1++;
    }
    for(i=j-1;i>=0;i--)
    printf("%lld",ar[i]);
    printf(" is %lld (mod 2).\n",num1);
}

int main()
{
    long long int a;
    while(scanf("%lld",&a)!=EOF)
    {
        if(a==0)
        break;
        digit(a);
    }
    return 0;
}
