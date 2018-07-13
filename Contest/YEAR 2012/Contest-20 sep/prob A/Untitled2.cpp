#include <stdio.h>
#include<iostream>
#include <math.h>
#define MAX 10000010
using namespace std;
int len;
bool table[MAX];
int prime[1000000];
void seive()
{
table[0]=table[1]=true;
int i,j;
for(i=4;i<=MAX;i+=2) table[i]=true;
for(i=3;i*i<=MAX;i+=2)
if(table[i]==0)
for(j=i*i;j<=MAX;j+=i)
table[j]=true;
prime[0]=2;
for(i=3,j=0;i<=MAX;i+=2)
if(table[i]==false) prime[++j]=i;
len=j;
}
bool isprime(long long int a)
{
int n,i;
n=sqrt(a);
 for(i=0;prime[i]<=n;i++)
   {
     if(a%prime[i]==0)
     return false;
    }
    return true;
}
int main ()
{
    seive();
    long long int n,num,flag,x,y,i,j;
    int k;
    for(k=0;;k++)
    {
        scanf("%lld",&num);
        if(num==0)
        break;
        if(num<0)
        num=-1*num;
        if(isprime(num)==true)
        {
            cout << "-1\n";
            continue;
        }
        flag=0;
        x=0;y=0;
        n=sqrt(num);
        for(i=2;i<=n;i++)
        {
            //printf("%lldi ",i);
            if(num%i==0)
            {
                x=num/i;
                if(isprime(x)==true)
                {
                    if(x*x==num)
                    flag=1;
                    y=x;
                   // printf("%lldi %lldy %lldx %lldf ",i,y,x,flag);
                    break;
                   //printf("%lldi %lldy ",i,y);
                }
                else if (isprime(i)==true)
                {
                    y=i;
                    if(i>=2)
                    {
                        for(j=i; j<=num;j=j*i)
                        {

                            if(num==j)
                            {
                                flag=1;
                                break;
                            }
                        }
                    }
                }
				if(flag==1)
				break;
        }
        }
        if(flag==1)
        printf("-1\n");
        else
        printf("%lld\n",y);
    }
    return 0;
}
