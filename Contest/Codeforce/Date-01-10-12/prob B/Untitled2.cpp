#include <stdio.h>
#include <math.h>
#include <iostream>
#define MAX 1000010
using namespace std;
int table[MAX];
void seive()
{
table[0]=table[1]=true;
int i,j;
for(i=4;i<=MAX;i+=2) table[i]=true;
for(i=3;i*i<=MAX;i+=2)
if(table[i]==0)
for(j=i*i;j<=MAX;j+=i)
table[j]=true;
}
/*bool isprime(long long int a)
{
int n,i;
n=sqrt(a);
 for(i=0;prime[i]<=n;i++)
   {
     if(a%prime[i]==0)
     return false;
    }
    return true;
}*/
int main()
{
    seive();
    long long int num[100010],sq,m;
    long long int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    for(i=0;i<n;i++)
    {
    if(num[i]==1)
     {
        printf("NO\n");
        continue;
     }
        sq=sqrt(num[i]);
        if(sq*sq!=num[i])
        {
            printf("NO\n");
            continue;
        }
        if(table[sq]==false)
         printf("YES\n");
         else
        printf("NO\n");

       /*else
       {
        if(isprime(num[i])==1)
        printf("YES\n");
        else
        printf("NO\n");
       }*/
    }
return 0;
}
