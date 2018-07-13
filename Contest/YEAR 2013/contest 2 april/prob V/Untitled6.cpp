#include <stdio.h>
#include <string.h>
#include <math.h>
bool table[10000001];
int prime[5000001],num_p,gc[10000001],low,high;
void seive()
{
memset(table,false,sizeof(table));
table[0]=table[1]=true;
int i,j;
for(i=4;i<=10001000;i+=2) table[i]=true;
for(i=3;i*i<=10001000;i+=2)
if(table[i]==0)
for(j=i*i;j<=10001000;j+=i)
table[j]=true;
prime[0]=3;
for(i=5,j=0;i<10001000;i+=2)
if(table[i]==false) prime[++j]=i;
num_p=j;
//printf("%d\n",num_p);
}
long long ans(int n)
{
    int i,j;
    long long int res=0;
    for(i=0,j=num_p-1;i<j;i++)
    {
        while(j>i&&prime[j]+prime[i]>n)
            j--;
        res+=j-i;
    }
    return res;
}
int main()
{
    seive();
    while(scanf("%d %d",&low,&high)){
        if(low==0 && high==0)
        break;
        printf("%lld\n",ans(high)-ans(low-1));
    }
    return 0;
}
