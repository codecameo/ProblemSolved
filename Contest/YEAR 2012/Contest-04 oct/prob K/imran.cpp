#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char s[1000010];
int main()
{
    cin>>s;
    int l=strlen(s);
    sort(s,s+l);
    int sum=0;int base;
    for(int i=0;i<l;i++)
    {
        if(s[i]<='9')   sum+=s[i]-'0',base=s[i]-'0';
        else sum+=s[i]-'A'+10,base=s[i]-'A'+10;
    }
    //cout<<sum<<endl;
    if(base<2)
    {
        puts("2\n");
        return 0;
    }
    bool flag=false;
    for(int i=base+1;i<=36;i++)
        if(sum%(i-1)==0)
        {
            flag=true;
            printf("%d\n",i);
            break;
        }
    if(!flag)   puts("No solution.");
}
