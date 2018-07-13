#include <stdio.h>
int main ()
{
    long long int k,i,j,a,b,c,e;
    for(k=1;;k++)
    {
    scanf("%lld %lld",&a,&b);
    if(a==0 && b==0)
    break;
    e=0;
    c=0;
    for(i=a,j=b;i>0 || j>0;i=i/10,j=j/10)
    {
        a=i%10;
        b=j%10;
        if(a+b+e>9)
        {
            e=1;
            c++;
        }
        else
        e=0;
    }
        if(c==0)
        printf("No carry operation.\n");
        else if(c==1)
        printf("1 carry operation.\n");
        else
        printf("%d carry operations.\n",c);

    }


    return 0;
}
