#include <stdio.h>
#include <string.h>
int dp[100010];
int graundy_num(int x)
{
    //printf("%d\n",x);
    int a,i;
    if(dp[x]!=-1) return dp[x];
    bool table[500];
    memset(table,false,sizeof(table));
    a=(x-1)/2;
    for(i=1;i<=a;i++)
    {
       // puts("jhfj");
        if(dp[i]==-1) graundy_num(i);
        if(dp[x-i]==-1) graundy_num(x-i);
        table[dp[i]^dp[x-i]]=true;
    }
    //puts("jhfj");
    int k=0;
    while(table[k]==true)
    k++;
    dp[x]=k;
    return k;
}
int main()
{
    int t,i,n,num,kase=1,nim;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    //dp[0]=0;dp[1]=0;dp[2]=0;dp[3]=1;
    while(t--)
    {
        int sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num);
            nim=graundy_num(num);
            sum^=nim;
        }
        printf("Case %d: ",kase++);
        if(sum)
        puts("Alice");
        else
        puts("Bob");

    }

    return 0;
}
