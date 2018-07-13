#include <stdio.h>
#include <algorithm>
#define MAX 1500000
using namespace std;
long long int phi[MAX] ;
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

int main ()
{
    sievePHI();
    int tcase,n,ar[10005],j,kase=0;
    long long int sum,i;
    scanf("%d",&tcase);
    while(tcase--)
    {
      scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ar[i]);
        }
        sort(ar,ar+n);
        for(i=2,j=0,sum=0;j<n;i++)
        {
            if(ar[j]<=phi[i])
            { for(;j<n;j++)
                {
                  //printf("%lld %d %lld\n",sum,ar[j],phi[i]);
                  if(ar[j]<=phi[i])
                  sum+=i;
                  else
                  break;
                }
            }
        }
        printf("Case %d: %lld Xukha\n",++kase,sum);
    }
}



