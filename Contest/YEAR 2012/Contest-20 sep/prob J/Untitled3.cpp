#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#define MAX 10000000
using namespace std;
int prime[1000000];
bool table[MAX];
void sieve()
{
memset(table,0,sizeof(table));
table[0]=table[1]=true;
int i,j;
for(i=4;i<=MAX;i+=2) table[i]=true;
for(i=3;i*i<=MAX;i+=2)
if(table[i]==0)
for(j=i*i;j<=MAX;j+=i)
table[j]=1;
prime[0]=2;
for(i=3,j=0;i<MAX;i+=2)
if(table[i]==0) prime[++j]=i;
}
int main ()
{
    sieve();
    int kase=1,tcase,a,c,i,count,num;
  cin>>tcase;
  while(tcase--)
  {
      cin>>num;
    for(i=0,count=0;prime[i]<=num/2;i++)
    {
        if(table[num-prime[i]]==0)
        count++;
    }
    printf("Case %d: %d\n",kase,count);
    kase++;
  }
    return 0;
}
