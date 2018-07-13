#include <stdio.h>
#include <string.h>
int main ()
{
    int l,i,m,j,s;
    char a[2000010],ch[2000010],b[2000010];
    while(gets(ch)!=0)
    {
        l=strlen(ch);
        for(i=0;i<l;i++)
        {
            if(ch[i]==' ')
            break;
            a[i]=ch[i];
           // printf("%d ",i);
        }
         m=i;
         for(i=m+1,j=0;i<l;i++,j++)
         {
             b[j]=ch[i];
         }
         //puts(a);puts(b);
         l=strlen(b);
         //printf("%d ",l);
        for(i=0,s=0;i<m;i++)
        {
            for(j=i;j<l;j++)
            {
                if(a[i]==b[j])
            {
                s++;
                break;
            }
            }
        }
        if(s==m)
        printf("Yes\n");
        else if(s<m)
        printf("No\n");
    }
    return 0;
}
