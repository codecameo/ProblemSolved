#include <stdio.h>
int main()
{
    int a,n,sum,num;
    scanf("%d",&n);
    if(n<0)
    num=n*-1;
    else
    num=n;
    sum=(num*(num+1))/2;
    if(n<0)
    sum=-1*(sum-1);
    if(n==0)
    sum=1;
    printf("%d\n",sum);
    return 0;
}
