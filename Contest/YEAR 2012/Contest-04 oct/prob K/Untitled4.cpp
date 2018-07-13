#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main ()
{
    char s[1000010];
    int k,i,a,max,l;
    bool flag;
    cin>>s;
    l=strlen(s);
    long long int sum=0;
    for(i=0,max=-1;i<l;i++)
    {
    if(s[i]<='9'){
        a=s[i]-'0';
    sum+=a;}
    else {
    a=s[i]-'A'+10;
    sum+=a;
    }
//printf("%d\n",a);
if(max<a)
max=a;
}
//printf("%d %d\n",sum,max);
if(max<2)
{
    printf("2\n");
    return 0;
}
  for(k=max,flag=false;k<36;k++)
    {
        if(sum%k==0)
        {
            flag=true;
            printf("%d\n",k+1);
            break;
        }
    }
    if(flag==false)
    printf("No solution.\n");
    return 0;
}
