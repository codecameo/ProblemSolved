#include <stdio.h>
#include <string.h>
#include <math.h>
bool table[10000000];
int prime[1000000];
void seive()
{
memset(table,false,sizeof(table));
table[0]=table[1]=true;
int i,j;
for(i=4;i<=10000000;i+=2) table[i]=true;
for(i=3;i*i<=10000000;i+=2)
if(table[i]==0)
for(j=i*i;j<=10000000;j+=i)
table[j]=true;
prime[0]=2;
for(i=3,j=0;i<10000000;i+=2)
if(table[i]==false) prime[++j]=i;
}
int numOfdiv(long long int n)
{
    int tmp = sqrt((double)n),i ;
    int ret = 1 ;

    for(i=0;prime[i]<=tmp;i++)
    {
        if(n % prime[i] == 0)
        {
            long long unsigned cnt =  0 ;
            while(n % prime[i] == 0)
            {
                cnt ++ ;
                n /= (long long unsigned)prime[i] ;
            }
            ret *= (cnt+1) ;
            tmp = sqrt((double)n) ;
        }
    }

    if(n>1)     ret *= 2 ;

    return ret ;
}

int main ()
{
    int tcase,kase=1;
    long long int num;
    int div;
    seive();
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%lld",&num);
         div=numOfdiv(num);
        printf("Case %d: %d\n",kase,div-1);
        kase++;
    }

    return 0;
}
