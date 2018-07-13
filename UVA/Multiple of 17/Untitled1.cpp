#include <stdio.h>
#include <string.h>
int main ()
{
    char num[100000];
    int a,l,i,j;
    for(i=0;;i++)
    {
        gets(num);
        if(num[0]=='0')
        break;
        l=strlen(num);
        for(j=0,a=0;j<l;j++)
        {
            a=((a*10)+(num[j]-'0'));
            a=a%17;
        }
        if(a==0)
        printf("1\n");
        else
        printf("0\n");
    }

    return 0;
}
