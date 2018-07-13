#include <stdio.h>
#include <string.h>
int main ()
{
    char ch[1000000];
    int l,i,k=0;
    while(gets(ch)!=0)
    {
        l=strlen(ch);
        for(i=0;i<l;i++)
        {
            if(ch[i]=='"')
            {
               k++;
               if(k%2!=0)
               printf("``");
               else
               printf("''");
            }
            else
            printf("%c",ch[i]);
        }
        printf("\n");
    }
return 0;
}
