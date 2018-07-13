#include <stdio.h>
long long int low,high,mid,cnt[30000],n,m,count;
void change()
{
    int sum,i;
    //printf("%lld %lld %lld",low,mid,high);
    for(i=0,count=0,sum=0;i<n;i++)
    {
        sum+=cnt[i];
        if(sum>mid)
        {
            count++;
            sum=0;
            sum+=cnt[i];
        }
    }
    //printf(" %lld\n",count+1);
}
int main ()
{
    int tcase,kase=0;
    long long int i,max,ans=0,s;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0,max=-1,s=0;i<n;i++)
        {
            scanf("%lld",&cnt[i]);
            s+=cnt[i];
            if(max<cnt[i])
            max=cnt[i];
        }
       low=max;
       high=s;
       while(high>=low)
       {
           mid=(high+low)/2;
           change();
             if(count+1>m)
                {
                    low=mid+1;
                }
                else if(count+1<m)
                {
                    high=mid-1;
                }
                else if(count+1==m)
                {
                    ans=mid;
                    high=mid-1;
                }
         //printf("%lld\n",ans);
       }
       printf("Case %d: %lld\n",++kase,ans);

    }
    return 0;
}
