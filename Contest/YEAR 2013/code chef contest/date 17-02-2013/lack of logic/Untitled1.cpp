#include <stdio.h>
#include <map>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
map<char,bool>m;
int t,i,l;
char st[10000],c;
bool flag;
scanf("%d",&t);
getchar();
while(t--){
m.clear();
gets(st);
for(i=0;i<strlen(st);i++)
{
    if(st[i]>64 && st[i]<91)
    {
        st[i]=st[i]+32;
    }
 m[st[i]]=1;
}
//cout<<st<<endl;
for(i=97,flag=0;i<123;i++){
c=i;
if(m[c]==0)
{
    printf("%c\n",c);
    flag=1;
    break;
}
}
if(flag==0)
printf("~\n");
//for()
}
return 0;
}
