#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char s[100010],st[100010];
int main()
{
    int i=0,count,k,l,len;
    gets(st);
    //puts(st);
    len=strlen(st);
    while(st[i]==' ') i++;
    for(i=i,count=0,l=0,k=0;i<len;i++)
    {
       if(st[i]=='"')
           {
               if(count==0)
               count++;
               else if(count==1)
               {
                   //printf("<%s>\n",s);
                   cout<<'<'<<s<<'>'<<endl;
                   memset(s,0,sizeof(s));
                   l=0;
                   //strcpy(s,NULL);
                   count=0;
                   //printf("%d\n",count);
               }
               continue;
           }
       if(count==1 && st[i]!='"')
       {
         s[l++]=st[i];

         continue;
       }
       if(st[i]==' ')
       {
           if(strlen(s))
           {
               cout<<'<'<<s<<'>'<<endl;
              //printf("<%s>\n",s);
              //reset(s2,k);
              //strcpy(s2,s1);
              memset(s,0,sizeof(s));
              k=0;
           }
           continue;
       }
       else if(st[i]!=' '){
       s[k++]=st[i];

       }
     }
     if(strlen(s))
     //printf("<%s>\n",s);
     cout<<'<'<<s<<'>'<<endl;
    return 0;
}
