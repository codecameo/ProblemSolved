#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char ch1[100000],ch2[100000];
int main ()
{
   char a[100];
   int l1,l2,k,i,j,count;
    while(gets(a)!=0)
    {
        k=atoi(a);
    while(k--)
    {
      gets(ch1);
      gets(ch2);
      l1=strlen(ch1);
      l2=strlen(ch2);
      if(l1!=l2)
      {
          printf("No\n");
          continue;
      }
      else
      for(i=0,count=0;i<l1;i++)
      {
          if(ch1[i]==ch2[i])
          {
              count++;
              continue;
          }
          else if(ch1[i]!=ch2[i]);
          {
              if(ch1[i]=='a' || ch1[i]=='e' || ch1[i]=='i' || ch1[i]=='o' || ch1[i]=='u')
                {
                if(ch2[i]=='a' || ch2[i]=='e' || ch2[i]=='i' || ch2[i]=='o' || ch2[i]=='u')
            count++;
            else
            {
                printf("No\n");
                break;
            }
                }
            else
            {
              printf("No\n");
                break;
            }
          }
      }
      if(count==l1)
      printf("Yes\n");
    }
    }
    return 0;
}
