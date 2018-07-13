#include <stdio.h>
#include <math.h>
int main ()
{
    int a,i,k,c,b;
    while(scanf("%d",&a)!=EOF)
    {
    if(a==0)
    break;
    b=sqrt(a);
    c=0;
    for(i=1;i<=b;i++)
    {
        if(a%i==0)
        c=c+2;
    }
    if(a=b*b)
    c--;
    if(c%2==0)
    printf("no\n");
    else
    printf("yes\n");
}
    return 0;
}

