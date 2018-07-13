#include <stdio.h>
#include <math.h>
#define MAX 5000001
int phi[MAX];
unsigned long long sq[MAX];
void sievePHI(){
	int i,j;
	for( i=2;i<MAX;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<MAX; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	sq[i]=phi[i];
	sq[i]*=phi[i];
	sq[i]+=sq[i-1];
}
}
int main ()
{
    sievePHI();
    unsigned long long int sum;
   int tcase,kase=1,i,a,b;
   scanf("%d",&tcase);
   while(tcase--)
    {
        sum=0;
        scanf("%d %d",&a,&b);
        sum=sq[b]-sq[a-1];
    printf("Case %d: %llu\n",kase,sum);
    kase++;
    }
    return 0;
}
