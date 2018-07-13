#include<stdio.h>
#include <math.h>
#define MAX 4000010
using namespace std;
int phi[MAX] ;
long long int g[MAX];
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

 for(int i=1;i<=MAX;i++)
        {
        for(int j=2;j*i<=MAX;j++)
        {
            g[j*i]+=i*phi[j];
        }
        }
for(i=1;i<=MAX;i++)
g[i]=g[i-1]+g[i];

}
int main()
{
	sievePHI();
	int n,i;
	while(scanf("%d",&n) && n)
	{
		printf("%lld\n",g[n]);
	}
	return 0;
}
