#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100100
int table[MAX],prime[MAX][7];
void seive()
{
    memset(table,0,sizeof(table));
    //table[0]=table[1]=1;
    int i,j;
    for(i=2;i<=MAX;i+=2)
    {
        table[i]++;
    }
    for(i=3;i<MAX;i+=2)
    {
        if(table[i]==0)
        for(j=i;j<=MAX;j+=i)
        {
            table[j]++;
        }
    }
    prime[1][1]=prime[1][2]=prime[1][3]=prime[1][4]=prime[1][5]=0;
    int count=0;
    for(i=2;i<=MAX;i++)
    {
        prime[i][1]=prime[i-1][1];
        prime[i][2]=prime[i-1][2];
        prime[i][3]=prime[i-1][3];
        prime[i][4]=prime[i-1][4];
        prime[i][5]=prime[i-1][5];

        if(table[i]<=5)
        prime[i][table[i]]++;
        /*if(i<30030 && table[i]!=1 && table[i]!=2 && table[i]!=3 && table[i]!=4 && table[i]!=5)
        {
            count++;
            printf("%d ",i);
        }*/
        //printf("%d %d %d %d %d\n",prime[i][1],prime[i][2],prime[i][3],prime[i][4],prime[i][5]);
     }
    //printf("%d\n",prime[2000000][8]);
    //printf("%d %d %d %d %d\n",prime[30029][1],prime[30029][2],prime[30029][3],prime[30029][4],prime[30029][5]);
    //printf("%d\n",prime[30029][1]+prime[30029][2]+prime[30029][3]+prime[30029][4]+prime[30029][5]);
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
