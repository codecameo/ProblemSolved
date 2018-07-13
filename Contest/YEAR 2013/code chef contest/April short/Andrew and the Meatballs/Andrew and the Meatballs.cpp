#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int t,n,count,i;
    long long int ar[10],sum,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %lld",&n,&m);
        for(i=0;i<n;i++)
        scanf("%lld",&ar[i]);
        sort(ar,ar+n);
        for(i=n-1,sum=0,count=0;i>=0;i--)
        {
            count++;
            sum+=ar[i];
            if(sum>=m)
            break;
        }
        if(i!=-1)
        printf("%d\n",count);
        else
        puts("-1");
    }
}
