#include <stdio.h>
int main(){
long long int count,n,a;
int t,kase=1;
scanf("%d",&t);
while(t--)
{
    count=0;
    scanf("%lld",&n);
    if(n==0)
    {
        printf("Case %d: 0\n",kase++);
        continue;
    }
    n++;
    while(n)
    {
        count++;
        a=n/2;
        n=n-a;
        if(n==1)
        break;
        if(n==2)
        {
            count++;
            break;
        }
    }
    printf("Case %d: %lld\n",kase++,count);
}
return 0;
}
