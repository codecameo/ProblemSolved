#include <stdio.h>
#include <math.h>
int main ()
{
    int i,j,k,l,n;
    char ch[100000],ch1[100000][100000];
    while(gets(ch)!=)
    {
        l=strlen(ch);
        n=sqrt(l);
        if(l!=(n*n))
        {
            printf("INVALID\n");
            continue;
        }
        for(i=0,k=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            ch1[i][j]=ch[k];
            k++;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            printf("%c",ch1[j][i]);
        }


    }
    return 0;
}
