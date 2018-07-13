#include <stdio.h>
#define mod 10056
long long int ar[1100],sum;
int num[1100];
void tt()
{
    int i,j;
    for(i=1;i<=1001;i++)
    {
        for(j=i,sum=0;j>1;j--)
        {
            ar[j]=((ar[j]+ar[j-1])*j)%mod;
            sum+=ar[j]%mod;
        }
        num[i]=(sum+1)%mod;
    }
}
int main()
{
    int n,kase=1,t;
    ar[1]=1;
    tt();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("Case %d: %d\n",kase++,num[n]);
    }
    return 0;
}
