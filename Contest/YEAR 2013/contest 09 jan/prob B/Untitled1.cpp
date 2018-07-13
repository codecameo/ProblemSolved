#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main(){
long long int i,j,v,tcase,l,sum,res;
char st1[1000000],st[1000000];
cin>>tcase;
getchar();
while(tcase--)
{
    gets(st1);
    l=strlen(st1);
    for(i=0,j=0,v=0;i<l;i++){
     if(st1[i]!=' ')
     st[j++]=st1[i];
     if(st1[i]=='a' || st1[i]=='e' || st1[i]=='i' || st1[i]=='o' || st1[i]=='u')
     v++;
    }
    st[j]=st[0];
    //puts(st);
    //cout<<v<<endl;
    //l=strlen(st);
    for(i=1,sum=0;i<=j;i++)
    {
        sum+=abs(st[i-1]-st[i]);

    }
    res=sum*v;
    cout<<res<<endl;

}
return 0;
}
