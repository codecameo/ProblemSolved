#include <stdio.h>
#include <string.h>
int main ()
{
    int i,j=0,s,l1,l2,k=0;
    char a[100000],b[100000];
    while(scanf("%s %s",a,b)!=EOF)
    {
       l1=strlen(a);
       l2=strlen(b);
        for(j=0,i=0,s=0,k=0;j<l2;j++)
        {
            if(a[i]==b[j])
            {
                 i++;
                 s++;
            if(s==l1)
            {
                printf("Yes\n");
                k++;
                break;
            }
            }

        }
        //printf("%d ",s);
        if(k==0)
        printf("No\n");
    }
    return 0;
}

