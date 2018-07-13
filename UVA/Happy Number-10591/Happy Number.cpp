#include <stdio.h>
#include <string.h>
long long int ar[1000000];
int main ()
{
    long long int t,i,sum=0,kase,n,d,j,num,c,k,index;
    scanf("%lld",&t);
        kase=1;
        while(t--)
        {
            index=-1;
            memset(ar,0,sizeof(ar));
            scanf("%lld",&num);
            n=num;
            for(j=0;;j++)
            {
            c=1;
            for(k=0;k<=index;k++)
            {
               if(ar[k]==n)
               c=0;
            }
            if(c==0)
            break;
            else if(c==1)
            {
             index++;
             ar[index]=n;
            }
            for(i=n,sum=0;i>0;i/=10)
            {
                d=i%10;
                sum=sum+(d*d);
            }
            n=sum;
            if(sum==1)
            break;
            }
            if(sum==1)
            printf("Case #%lld: %lld is a Happy number.\n",kase,num);
            else
            printf("Case #%lld: %lld is an Unhappy number.\n",kase,num);
            kase++;
        }
    return 0;
}
