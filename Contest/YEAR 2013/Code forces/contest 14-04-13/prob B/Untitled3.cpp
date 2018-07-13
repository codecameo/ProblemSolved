#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
char s[1000010],s1[100010],s2[100010];
void reset(char a[],int x)
{
    int i;
    for(i=0;i<=x;i++)
    a[i]=NULL;

}
//string s,s1;
int main()
{
    int i,count,k,l;
    char st[100010];
    gets(st);
    for(i=0,count=0,l=0,k=0;i<strlen(st);i++)
    {
        //printf("%c\n",st[i]);
        //puts(s);
        //puts(s1);
        puts(s2);
       if(st[i]=='"')
           {
               if(count==0)
               count++;
               else if(count==1)
               {
                   printf("<%s>\n",s);
                   reset(s,l);
                   l=0;
                   //strcpy(s,s1);
                   count=0;
                   //printf("%d\n",count);
               }
               continue;
           }
       if(count==1)
       {
         s[l++]=st[i];
         //puts(s);
         continue;
       }
       if(st[i]!=' ')
       {
           if(strlen(s2))
           {
              printf("<%s>\n",s2);
              //strcpy(s2,s1);
              puts(s2);
              reset(s2,k);
              k=0;
           }
           continue;
       }
       else if(st[i]!=' ')
       s2[k++]=st[i];
     }
     if(strlen(s2))
     //printf("<%s>\n",s2);

    return 0;
}
