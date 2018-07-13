#include <stdio.h>
#include <string.h>
int main ()
{
    int c=0,i,j,l,k,a,b=0;
    char ch[100000],ch1[10];
    for(k=0;;k++)
    {
        gets(ch);
        strcpy(ch1,"DONE");
        a=strcmp(ch1,ch);
        if(a==0)
        break;
        l=strlen(ch);
        for(i=0,j=l-1;i<j;)
        {
            b++;
            if(ch[i]<'A' || ch[i]>'z' || ch[i]==' ')
            {
                i++;
               continue;
            }
            if(ch[j]<'A' || ch[j]>'z' || ch[j]==' ')
            {
                j--;
               continue;
            }
            if(ch[i]!=ch[j])
            {
                if(ch[i]+32!=ch[j])
                if(ch[i]-32!=ch[j])
                {
                c++;
                break;
                }
            }
            i++;
       j--;
        }
        if(c==0)
        printf("You won't be eaten!\n");
        if(c==1)
        printf("Uh oh..\n");
        c=0;

    }
    return 0;
}
