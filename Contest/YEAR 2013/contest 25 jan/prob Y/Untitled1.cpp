#include <stdio.h>
#include<math.h>
#define MAX 1000000
int primes[MAX] ;
bool sieve[MAX] ;

void genPrimes()
{
    primes[l++] = 2 ;
    long long i,j ;
    for(j=4;j<MAX;j+=2)
    sieve[j] = 1 ;
    for(i=3;i<MAX;i+=2)
    {
              if(sieve[i]==0)
              {
                        primes[l++] = i ;
                        for(j=i*i;j<MAX;j+=i)               sieve[j] = 1 ;
              }
    }
}
int phi[MAX] ;
void sievePHI(){
	long long i,j;
	for( i=2;i<MAX;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<MAX; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	}
}
int main(){
genPrimes();
sievePHI();
scanf("%d",&t);
while(t--){
scanf("%d %d",&k,&p);

}
}

