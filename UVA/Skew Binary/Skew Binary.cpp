#include <stdio.h>
#include <math.h>
#include <string.h>
int main ()
{
    int c,a,b,l,sum;
    char num[100000];
    while(gets(num)!=EOF)
    {
        c=strcmp(num,"0");
        if(c==0)
        break;
        l=strlen(num);
        for(i=0,j=l,sum=0;i<l;i++,j--)
        {
            a=num[i]-'0';
            b=pow(2,j)-1
            b=b*a;
            sum=sum+b;
        }
        printf("%d\n",sum);


    }
    return 0;
}
