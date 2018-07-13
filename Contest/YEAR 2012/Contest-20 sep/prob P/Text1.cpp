#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100000010
int l;
int primes[MAX];
bool sieve[MAX] ;
void genPrimes()
{
    primes[l++] = 2 ;

    long int i,j ;

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

long int phi[MAX];
void sievePHI(){
	long  int i,j;
	for( i=2;i<=MAX;i++){
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
void fact(unsigned long int a)
{
    float c=1.0;
    unsigned long int x,i=0;
    while(primes[i]<=a/2)
    {
        if(a%primes[i]==0)
        {
            printf("%d ",primes[i]);
           c=c*(1.0*primes[i]-1)/(1.0*primes[i]);
        }
      i++;
    }
    x=c*(1.0*a);
    printf("%llu\n",x);
}

int main ()
{
    int i;
    unsigned long int num;
    //printf("%d\n",sieve[333667]);
    genPrimes();
    //printf("%d\n",primes[0]);
    sievePHI();
    for(i=0;;i++)
    {
        scanf("%llu",&num);
       if(num==0)break;
          if(sieve[num]==0)
          {
              printf("%lld\n",num-1);
              continue;
          }
       // if(num<=100000000)
        //printf("%lld\n",phi[num]);
        //else
        //{
          fact(num);
        //}
    }

    return 0;
}
