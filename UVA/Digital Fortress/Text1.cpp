#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
 char ch[100000],ch1[10000][10000],tcase[100000];
int main ()
{
    int i,j,k,l,n,a;
    gets(tcase);
    a=atoi(tcase);
	while(a--)
		{
		 gets(ch);
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
            {
			ch1[i][j]=ch[k];
            k++;
			}
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            printf("%c",ch1[j][i]);
        }
		printf("\n");
		}
    return 0;
}
