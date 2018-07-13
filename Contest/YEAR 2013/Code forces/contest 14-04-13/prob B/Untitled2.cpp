#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//char s[1000010],s1[1];
string s,s1;
int main()
{
    int i,count;
    //gets(s);
    s+='c';
    cout<<s<<endl;
    //strcpy(s,s1);
    s=s1;
    cout<<s<<endl;
    char st[100010];
    gets(st);
    for(i=0,count=0;i<strlen(st);i++)
    {
       if(st[i]=='"' && count==0)
           {
               count++;
               continue;
           }
       if(count==1)
       {

       }


    }

    return 0;
}
