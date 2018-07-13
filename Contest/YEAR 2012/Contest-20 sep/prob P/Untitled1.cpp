#include <stdio.h>
#include <math.h>
#define MAX 100000000
int l ;
int primes[MAX] ;
bool sieve[MAX] ;
void genPrimes()
{
    primes[l++] = 2 ;

    long long int i,j ;

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

long long int phi[MAX];
void sievePHI(){
	long long int i,j;
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
int fact(long long int a)
{
    int i,j,fc[100000];
    memset(fc,0,sizeof(fc));
    for(i=0,j=0;primes[i]<=a/2;i++)
    {
        if(a%primes[i]==0)
        {
            fc[j]=primes[i];
            j++;
        }
    }

}

int main ()
{
    long long int i,num,x,y,d,n;
    bool a;
    float c;
    //printf("%d\n",sieve[333667]);
    genPrimes();
    //printf("%d\n",primes[0]);
    sievePHI();
    for(i=0;;i++)
    {
        scanf("%lld",&num);
       if(num==0)break;
          if(sieve[num]==0)
          {
              printf("%lld\n",num-1);
              continue;
          }
        if(num<=100000000)
        printf("%lld\n",phi[num]);
        else
        {
            n=num;
        for(i=0,a=0,c=1.0;n>1;)
        {
            if(n%primes[i]==0)
            {
                n/=primes[i];
                if(a==0)
                c*=((1.0*primes[i]-1)/primes[i]);
                a==1;
                //printf("%.6f\n",c);
            }
            else
            {
                i++;
                a=0;
            }
        }
        x=c*(1.0*num);
        printf("%lld\n",x);
        }
    }

    return 0;
}
