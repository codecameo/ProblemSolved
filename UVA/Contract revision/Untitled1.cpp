#include <stdio.h>
#include <string.h>
int main ()
{
   int a=0,i,l,b=1,k;
   char ch[100000],c;
    for(k=0;;k++)
    {
        scanf("%c",&c);
        getchar();
        scanf("%s",ch);
        getchar();
        b=strcmp(ch,"0");
        if(c=='0' && b==0)
        break;
        l=strlen(ch);
        for(i=0,a=0;i<l;i++)
        {
            //printf("%dm ",i);
            if(ch[i]!=c)
            {
                if(ch[i]=='0' && a==0)
                continue;
                else
                {
                    printf("%c",ch[i]);
                    a=1;
                }
            }

        }
        if(a==0)
        printf("0");
        printf("\n");
    }
    return 0;
}
