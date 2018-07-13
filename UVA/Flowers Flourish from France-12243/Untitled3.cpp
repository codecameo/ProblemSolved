#include <stdio.h>
#include <string.h>
int main ()
{
    int i,k,l,a,b;
    char line[100000];
    for(k=0;;k++)
    {
        gets(line);
        if(line[0]=='*')
        break;
        a=line[0];
        l=strlen(line);
        for(i=0;i<l;i++)
        {
            if(line[i]==' ')
            {
                b=line[i+1];
                if(line[i+1]!=line[0] && ((a>=97 && b!=(a-32)) || (a<97 && b!=(a+32))))
                break;
            }
        }
        if(i==l)
        printf("Y\n");
        else
        printf("N\n");

    }
    return 0;
}
