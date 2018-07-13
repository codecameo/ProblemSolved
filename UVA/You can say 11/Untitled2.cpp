#include <stdio.h>
#include <string.h>
char num[100000];
int main ()
{
    int a,l,i,j;
    while(gets(num)!=0)
    {
        if(strcmp(num,"0")==0) break;
        l=strlen(num);
        for(j=0,a=0;j<l;j++)
        {
            a=((a*10)+(num[j]-'0'));
            a=a%11;
        }
        if(a==0)
        printf("%s is a multiple of 11.\n",num);
        else
        printf("%s is not a multiple of 11.\n",num);
    }

    return 0;
}
