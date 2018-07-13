#include <stdio.h>
int main ()
{
    long long int i,b,n,m,x,y,k;
    for(k=0;;k++)
    {
    scanf("%lld",&b);
    if(b==0)
    break;
    scanf("%lld %lld",&x,&y);
    for(i=0;i<b;i++)
    {
    scanf("%lld %lld",&m,&n);
    if(m==x || n==y)
    printf("divisa\n");
    else if(m>x && n>y)
    printf("NE\n");
    else if(m<x && n<y)
    printf("SO\n");
    else if(m>x && n<y)
    printf("SE\n");
    else if(m<x && n>y)
    printf("NO\n");
    }
    }
return 0;
}
