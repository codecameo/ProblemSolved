#include <stdio.h>
int main ()
{
    long long int N;
    int i,j,c,b,ar[100000],k;
    for(k=1;;k++)
    {
    scanf("%lld",&N);
    if(N<0)
    break;
    else if(N==0)
    printf("0\n");
    else if(N>0)
    {for(i=N,j=0;i>0;i=i/3,j++)
    {
     b=(i%3);
     ar[j]=b;
     c=j;
    }
    for(i=c;i>=0;i--)
        printf("%d",ar[i]);
        printf("\n");
    }}
    return 0;
}
