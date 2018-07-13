#include <stdio.h>
#include <string.h>
int main ()
{
long long int l,i,count,a,k;
char ch[100000];
while(gets(ch)!=0)
{
  l=strlen(ch);
    for(i=0,k=0,count=0;i<l;i++)
    {
      if((ch[i]>='A' && ch[i]<='Z') || (ch[i]>='a' && ch[i]<='z'))
      {
        if(k==0)
        {
         k++;
         count++;
        }
       }
      else
      k=0;
    }
printf("%lld\n",count);
    }
return 0;
}
