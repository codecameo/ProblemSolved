#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int issubstring(char a[], char b[])
{
    int la,lb,i,j;
    la=strlen(a);
    lb=strlen(b);
    for(i=0;i<lb;i++)
    {
       // for(j=0;j<lb;j++)
            if(a[i]!=b[i])    return 0;
       // if(j==lb)   return 1;
    }
     if(i==lb)   return 1;
    return 0;
}
char s[100000000],c[100000];
int main()
{
    int T,q;
    scanf("%d\n",&T);
    while(T--&&gets(s))
    {
        int q;
        scanf("%d\n",&q);
        memset(c,0,sizeof(c));
        while(q--&&gets(c))
        {
            if(issubstring(s,c))    puts("y");
            else puts("n");
            memset(c,0,sizeof(c));
        }
    }
}
