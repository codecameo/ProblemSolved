#include <stdio.h>
#include <string.h>
//long long int num[100000000];
int main ()
{
    long long int count,i,a,b,j,n,m;
    while(scanf("%lld %lld",&n,&m)!=0)
    {
    if(n==0 && m==0)
    break;
    //memset(num,0,sizeof(num));
    long long int num[100000000]={0};

        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            num[a]=1;
        }
        for(i=0,count=0;i<m;i++)
        {
            scanf("%lld",&b);
            if(num[b]==1)
            count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
