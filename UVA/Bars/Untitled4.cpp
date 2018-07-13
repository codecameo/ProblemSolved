#include <stdio.h>
#include <string.h>
int main ()
{
    int tg,i,tcase,j,n;
    scanf("%d",&tcase);
    while(tcase-- && scanf("%d %d",&tg,&n))
    {
        int dp[100000],k;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&k);
            for(j=1000;j>=0;j--)
            {
                if(dp[j])
                dp[j+k]=1;
            }
        }
        if(dp[tg]==1)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
