#include <stdio.h>
int main ()
{
    int sum=1,i,n,count=0,cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0)
        break;
        for(i=0;i<n;i++)
        {
            if(sum>=n)
            break;
            sum=(sum*2);
            count++;
        }
        cas++;
    printf("Case %d: %d\n",cas,count);
    count=0;
    sum=1;
    }

    return 0;
}
