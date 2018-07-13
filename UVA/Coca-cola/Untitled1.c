#include <stdio.h>
int main ()
{
    int i,a,sum,b,c,d;
    for(i=1;i<=10;i++)
    {
        scanf("%d",&a);
        if(a==0)
        break;
        sum=0;
        for(;a>=3 || d>=3;a=d)
       {
        b=a/3;
        sum=sum+b;
        c=a%3;
        d=b+c;
        }
        if(d==2)
        sum++;
        printf("%d\n",sum);
    }


    return 0;
}
