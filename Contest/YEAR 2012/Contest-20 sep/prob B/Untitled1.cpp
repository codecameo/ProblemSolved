#include <stdio.h>
#include <math.h>
#include <string.h>
int sum[1000]={0};
char sum1[1000]={0};
long long int phi[5000010];
void sievePHI(){
	long long int i,j;
	for( i=2;i<=5000010;i++){
		if( phi[i]==0){
			phi[i] = i-1;
			for( j = i*2; j<5000010; j+=i){
				if( phi[j] == 0 )phi[j] = j;
				phi[j] /= i ;
				phi[j] *= (i-1) ;
			}
		}
	}
}
void fibo (char num1[],char num2[])
{
    memset(sum1,0,sizeof(sum1));
    memset(sum,0,sizeof(sum));
    int i,j,k,l1,l2;
    char p,q;
    l1=strlen(num1);
    l2=strlen(num2);
    for(k=0,i=l1-1,j=l2-1;i>=0 || j>=0;i--,j--,k++)
    {
        if(i<0)num1[i]='0';
        p=num1[i]-'0';
        if(j<0)num2[j]='0';
        q=num2[j]-'0';
        sum[k]=sum[k]+p+q;
        if(sum[k]>9)
        {
            sum[k+1]=sum[k]/10;
            sum[k]=sum[k]%10;
        }
    }
        for(i=999;i>=0;i--)
        {
            if(sum[i]!=0)
            {
            j=i;
            break;
            }
        }
        for(i=j,k=0;i>=0;i--,k++)
        {
            sum1[k]=sum[i]+'0';
        }
}

int main ()
{
   long long int sm,i,a,b,kase=1,tcase,s;
   char num[10000],sum2[10000];
   scanf("%lld",&tcase);
   sievePHI();
   while(tcase--)
    {
        strcpy(sum2,"0");
        scanf("%lld %lld",&a,&b);
        for(i=a,sm=0;i<=b;i++)
        {
            s=(phi[i]*phi[i]);
            sprintf(num,"%lld",s);
            fibo(sum2,num);
            strcpy(sum2,sum1);
        }
    printf("Case %lld: %s\n",kase,sum2);
    kase++;
    }
    return 0;
}
