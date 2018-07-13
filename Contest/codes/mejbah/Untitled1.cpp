#include<stdio.h>
#include<math.h>
int main()
{
    long long int k,s,carry,a,b,m,n,x,y,p,q;
    while(1)
    {
        scanf("%lld %lld",&a,&b);
        if(a==0 && b==0)break;
        if(a>=b)
        {
            m=a;
            n=b;
        }
        else
        {
            m=b;
            n=a;
        }
        s=0,carry=0;
        for(;;)
        {
            x=m/10;
            y=m%10;
            m=x;

            p=n/10;
            q=n%10;
            n=p;
            k=y+q;
            s=s+k;
            if(s>9)
            {
                carry++;
                s=1;
            }
            else
            s=0;
            if(x==0)break;

        }
        if(carry==0)
        printf("No carry operation.\n");
        else if(carry==1)
        printf("1 carry operation.\n");
        else
        printf("%lld carry operations.\n",carry);
    }
    return 0;
}
