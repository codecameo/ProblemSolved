#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 100000010
bool table[MAX];
int prime[MAX];
void seive()
{
memset(table,false,sizeof(table));
table[0]=table[1]=true;
int i,j;
for(i=4;i<=MAX;i+=2) table[i]=true;
for(i=3;i*i<=MAX;i+=2)
if(table[i]==0)
for(j=i*i;j<=MAX;j+=i)
table[j]=true;
prime[0]=2;
for(i=3,j=0;i<MAX;i+=2)
if(table[i]==false) prime[++j]=i;
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
void fact(long long int a)
{
    long long int i=0;
    float c=1.0;
    long long int x;
    while(i<MAX)
    {
        if(a%prime[i]==0)
        {
           printf("%d ",prime[i]);
           c=c*(1.0*prime[i]-1)/(1.0*prime[i]);
        }
        //if(prime[i]>a/2)
        //break;
      i++;
    }
    printf("dd\n");
    x=a;
    x=c*(1.0*x);
    printf("%lld\n",x);
}

int main ()
{
    int i;
    long long int num;
    //printf("%d\n",sieve[333667]);
    seive();
    //printf("%d\n",primes[0]);
    sievePHI();
    for(i=0;;i++)
    {
        scanf("%lld",&num);
       if(num==0)break;
          //if(table[num]==false)
         // {
           //   printf("%lld\n",num-1);
             // continue;
         // }
       // if(num<=100000000)
        //printf("%lld\n",phi[num]);
        //else
        //{
          fact(num);
        //}
    }

    return 0;
}
