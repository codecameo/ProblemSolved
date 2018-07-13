#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int num[110],i,j,l,len;
    char st[110];
    gets(st);
    l=strlen(st);
    for(i=0,j=-1;i<l;i++)
    {
        if(st[i]!='+')
        {
            num[++j]=st[i]-'0';
        }
    }
    len=j+1;
    sort(num,num+len);
    for(i=0;i<len;i++)
    {
        if(i)
        printf("+");
        printf("%d",num[i]);
    }
    puts("");
    return 0;
}
