#include <stdio.h>
#include <string.h>
int x;
char ch1[1000];
void cir(int I,char ch[])
{
    int i,j;
    //printf("%d %d ",I,x);
    for(i=I-1,j=0;j<=I-1-x;j++,i--)
    {
        ch1[j]=ch[i];
    }
    x=I+1;
   printf("%s",ch1);
   memset(ch1,NULL,sizeof(ch1));
}
int main ()
{
int i,l;
char ch[100000];
while(gets(ch)!=0)
{
    x=0;
    l=strlen(ch);
    for(i=0;i<l;i++)
    {
        if(ch[i]==' ')
        {
          cir(i,ch);
          printf(" ");
        }
    }
    cir(i,ch);
    //printf("a");
    printf("\n");
}
return 0;
}
