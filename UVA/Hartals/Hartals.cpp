#include <stdio.h>
#include <string.h>
int main ()
{
    int n,p,k,pr[110],ar[100000],i,a,sum;
    scanf("%d",&k);
    while(k--)
    {
        memset(ar,0,sizeof(ar));
        scanf("%d %d",&n,&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&pr[i]);
        }
        for(i=0;i<p;i++)
        {
            for(a=pr[i];a<=n;a=a+pr[i])
            {
                //printf("%d\n",a);
                if(a%7!=0 && (a+1)%7!=0)
                {
                    ar[a]=1;
                    //printf("%d\n",a);
                }
            }
        }
        for(i=0,sum=0;i<=n;i++)
        {
            if(ar[i]==1)
            sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
