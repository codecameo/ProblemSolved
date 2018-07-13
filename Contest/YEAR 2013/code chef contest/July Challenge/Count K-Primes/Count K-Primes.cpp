#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100010
int table[MAX],prime[MAX][6];
void seive()
{
    memset(table,0,sizeof(table));
    table[0]=table[1]=1;
    int i,j;
    for(i=4;i<=MAX;i+=2)
    {
        table[i]++;
    }
    for(i=3;i<sqrt(MAX);i+=2)
    {
        if(table[i]==0)
        for(j=i;j<=MAX;j+=i)
        {
            table[j]++;
        }
    }
    table[2]=1;
    prime[1][1]=prime[1][2]=prime[1][3]=prime[1][4]=prime[1][5]=0;
    for(i=2;i<=5;i++)
    {
        prime[i][1]=prime[i-1][1];
        prime[i][2]=prime[i-1][2];
        prime[i][3]=prime[i-1][3];
        prime[i][4]=prime[i-1][4];
        prime[i][5]=prime[i-1][5];
        prime[i][table[i]]++;
        printf("%d %d %d %d %d\n",prime[i][1],prime[i][2],prime[i][3],prime[i][4],prime[i][5]);
    }
}
int main()
{
    int t,b,a,k,ans,i;
    seive();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&k);
        ans=prime[b][k]-prime[a-1][k];
        printf("%d\n",ans);
    }
    return 0;
}
