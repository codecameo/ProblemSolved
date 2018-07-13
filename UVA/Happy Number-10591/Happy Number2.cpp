#include <stdio.h>
#include <string.h>
long long int a[1000000];
int main ()
{
    long long int t,i,sum=0,kase,n,d,j,num,c,k,index;
    scanf("%lld",&t);
        kase=1;
        while(t--)
        {
            scanf("%lld",&num);
            n=num;
            for(j=0;;j++)
            {
            for(i=n,sum=0;i>0;i/=10)
            {
                d=i%10;
                sum=sum+(d*d);
            }
            n=sum;
            if(sum<10)
            break;
            }
            if(sum==1 || sum==7)
            printf("Case #%lld: %lld is a Happy number.\n",kase,num);
            else
            printf("Case #%lld: %lld is an Unhappy number.\n",kase,num);
            kase++;
        }
    return 0;
}

