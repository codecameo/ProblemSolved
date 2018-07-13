#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int table[105];
int ages[105];
int main(){
int n,age,j;
for(;;)
{
    memset(table,0,sizeof(table));
    memset(ages,0,sizeof(ages));
    scanf("%d",&n);
    if(n==0)
        break;
    j=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&age);
        if(table[age]==0)
        {
            table[age]++;
            ages[j]=age;
            j++;
        }
        else
            table[age]++;
    }
    sort(ages,ages+j);
    for(int i=0;i<j;i++)
    {
        for(int k=0;k<table[ages[i]];k++)
        {
            printf("%d",ages[i]);
            if(i!=j-1)
                printf(" ");
            else if(k!=table[ages[i]]-1)
                printf(" ");
        }
    }
    puts("");
}
return 0;
}
