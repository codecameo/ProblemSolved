#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 10000000
using namespace std;
int l ;
int primes[MAX] ;
bool sieve[MAX] ;

void genPrimes()
{
    primes[l++] = 2 ;

    long long int i,j ;

    //for(j=4;j<MAX;j+=2)               sieve[j] = 1 ;

    for(i=3;i<MAX;i+=2)
    {
              if(sieve[i]==0)
              {
                        primes[l++] = i ;
                        for(j=i*i;j<MAX;j+=i)               sieve[j] = 1 ;
              }
    }
}

int main()
{
    long long int a=0,k,i,c,ans,l,j,d;
    char num[20],num1[20],num2[2];
    seive();
    for(k=0;;k++)
    {
        gets(num);
        strcpy(num2,"0");
        if(strcmp(num,num2)==0)
        break;
        l=strlen(num);
        for(i=0;i<MAX;i++)
        {
            for(j=0,a=0;j<l;j++)
            {
                a=((a*10)+(num[j]-'0'));
                a=a%primes[i];
            }
        if(a==0)
        ans=primes[i];
        }

    sprintf(num1,"%lld",ans);
     d=strcmp(num,num1);
     if(d==0)
     printf("-1\n");
     else
     printf("%lld\n",ans);

    }
    return 0;
}
