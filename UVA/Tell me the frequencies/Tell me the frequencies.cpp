#include <stdio.h>
#include <string.h>
int main ()
{
int a,i,l,f,sum,c=0;
char ch[100000];
memset(ch,0,sizeof(ch));
while(gets(ch)!=0)
{
    int num[10000]={0};
    if(c==1)
    printf("\n");
    c=1;
//getchar();
//memset(num,0,sizeof(num));
l=strlen(ch);
//printf("%d\n",l);
for(i=0;i<l;i++)
{
a=ch[i];
num[a]++;
}
for(f=1,sum=0;sum<l;f++)
{
    //printf(" tt ");
for(i=128;i>=32;i--)
{
    //printf(" ll ");
if(num[i]==f)
{
printf("%d %d\n",i,f);
sum=sum+f;
}
}
}
}
return 0;
}
