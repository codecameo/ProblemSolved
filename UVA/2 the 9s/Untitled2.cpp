#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
    int sum,i,l,count=0,j,a,k;
    char num[100000];
    while(gets(num)!=0)
    {
        if(num[0]=='0')
        break;
        l=strlen(num);
        for(i=0,sum=0,count=0;i<l;i++)
        {
            sum=sum+(num[i]-'0');
        }
        count++;
        if(sum%9==0 && sum>9)
        {
        for(i=sum;i>=10;i=sum)
        {
            sum=0;
            for(j=i;j>0;j=j/10)
            {
               a=j%10;
               sum=sum+a;
            }
            count++;
        }
        //printf("%d %d ",count,sum);
        }
        if(sum%9==0)
        {
          k=0;
        while(num[k]!=NULL)
        {
            printf("%c",num[k]);
            k++;
        }
        printf(" is a multiple of 9 and has 9-degree %d.\n",count);
        }
        else if(sum%9!=0)
        {
        k=0;
        while(num[k]!=NULL)
        {
            printf("%c",num[k]);
            k++;
        }
            printf(" is not a multiple of 9.\n");
        }
       // printf("%d",count);
    }
    return 0;
}
