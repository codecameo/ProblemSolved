#include <stdio.h>
#include <string.h>
char num[30001][21];
int main ()
{
    int tcase,i,l,j,len;
    bool flag;
    scanf("%d",&tcase);
    getchar();
    for(i=0;i<tcase;i++)
    {
        gets(num[i]);
    }
    l=strlen(num[1]);
    for(i=0;i<l;i++)
    {
     for(j=1,flag=0;j<tcase;j++)
        {
            if(num[0][i]!=num[j][i])
            {
                //printf("%c %c\n",num[0][i],num[j][i]);
                len=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }
    printf("%d\n",len);
    return 0;
}
