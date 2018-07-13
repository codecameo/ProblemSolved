#include<stdio.h>
#include<string.h>
int main()
{
    int i,k=0,len,cap,small;
    char a[20],str[100],c;
    for(;;)
    {
        gets(str);
        c=str[0];
        len=strlen(str);
        for(i=1;i<len;i++)
        {
            if(str[i]==' ')
            {
               if(str[i+1]>='A'){
                 if(c!=str[i+1] && c!=str[i+1]+32 && c!=str[i+1]-32)
                 break;
               }
               if(str[i+1]>='a'){
                 if(c!=str[i+1] && c!=str[i+1]-32 && c!=str[i+1]+32)
                 break;
               }
            }
        }
        printf("%d\n",i);
        if(i==len)
        printf("Y\n");
        else
        printf("N\n");
    }
return 0;
}
