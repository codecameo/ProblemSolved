#include <stdio.h>
#include <string.h>
int sum[1000]={0};
char sum1[1000]={0};
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
     int i,n,k;
     char num1[100000],num2[100000];
     while(scanf("%d",&n)==1)
    {
        strcpy(num1,"0");
        strcpy(num2,"1");
     for(i=2;i<=n;i++)
     {
         fibo(num1,num2);
         strcpy(num1,num2);
         strcpy(num2,sum1);
         puts(sum1);
     }
     //printf("%d\n",n);
     puts(num2);
    }
  return 0;
}
