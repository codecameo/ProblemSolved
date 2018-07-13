#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 10010
bool table[MAX];
int prime[MAX];
void seive()
{
    memset(table,false,sizeof(table));
    table[0]=table[1]=true;
    int i,j;
    for(i=4;i<=MAX;i+=2) table[i]=true;
    for(i=3;i<sqrt(MAX);i+=2)
    {
        if(table[i]==false)
        for(j=i*i;j<MAX;j+=i)
        {
            table[j]=true;
        }
    }
    prime[0]=2;
    for(i=3,j=0;i<MAX;i+=2)
    if(table[i]==false){
    prime[++j]=i;
    //printf("%d ",i);
    }
}
int main()
{
    seive();
    int t,n,num,i;
    long long int ans;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d",&n);
        /*if(n%2==0)
        {
          if(n<=4)
          printf("0\n");
          else
          puts("1");
          continue;
        }*/
        for(i=0;prime[i]<=n-4;i++)
        {
            num=n-prime[i];
            //printf("%d ",prime[i]);
            if(num%2==1){
                //puts("jf");
            continue;
            }
            num=num/2;
            //printf("%d %d\n",prime[i],num);
            if(table[num]==false)
            ans++;
        }
        printf("%lld\n",ans);
    }

    return 0;
}
