#include <stdio.h>
#include <string.h>
long long int jack[100000000],jill[100000000];
int main ()
{
    long long int count,i,j,n,m;
    memset(jill,0,sizeof(jill));
    memset(jack,0,sizeof(jack));
    while(scanf("%lld %lld",&n,&m)!=0)
    {
        if(n==0 && m==0)
        break;
        for(i=0;i<n;i++)
        scanf("%lld",&jack[i]);
        for(i=0;i<m;i++)
        scanf("%lld",&jill[i]);
        for(i=0,count=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
            if(jack[i]==jill[j])
            {
                count++;
                break;
            }
            //else if(jack[i]<jill[j])
            //break;
            }
        }
        printf("%lld\n",count);
    }
    return 0;
}
