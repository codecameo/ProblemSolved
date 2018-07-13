#include <stdio.h>
#include <math.h>
#include<iostream>
#define MAX 1000001
using namespace std;
long long int phi[MAX] ;
void sievePHI(){
	int i,j;
	phi[1]=1;
	for( i=2;i<MAX;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<MAX; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	phi[i]=phi[i]*i;
	}
}
int main ()
{
    sievePHI();
    int tcase,i,num,n;
    long long int sum;
    cin>>tcase;
    while(tcase--)
    {
        cin>>num;
        for(i=1,sum=0;i<=sqrt(num);i++)
        {
            if(num%i==0)
            {
                sum+=phi[i];
                if(i*i!=num)
                {
                    sum+=phi[num/i];
                }
            }
        }
        sum=num*(1+sum)/2;
        cout<<sum<<endl;
    }
    return 0;
}
