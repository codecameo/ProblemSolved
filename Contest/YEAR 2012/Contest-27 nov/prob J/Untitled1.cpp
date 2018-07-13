#include <stdio.h>
#include<math.h>
#include <iostream>
#define MAX 100010
using namespace std;
int l=0;
int primes[MAX] ;
bool sieve[MAX] ;

void genPrimes()
{
    primes[l++] = 2 ;

    long long i,j ;

    for(j=4;j<MAX;j+=2)               sieve[j] = 1 ;

    for(i=3;i<MAX;i+=2)
    {
              if(sieve[i]==0)
              {
                        primes[l++] = i ;
                        for(j=i*i;j<MAX;j+=i)               sieve[j] = 1 ;
              }
    }
}

bool check(int x)
{
    if(x==1)
    return false;
    for(int i=0;primes[i]*primes[i]<=x;i++)
        if(x%primes[i]==0)
            return false;
    return true;
}
int main()
{
    int i,a,b,tcase;
    genPrimes();
    cin>>tcase;
    while(tcase--){
    cin>>a>>b;
     for(i=a;i<=b;i++){
     if(check(i))
     cout<<i<<endl;
     }
     cout<<endl;
    }
}
