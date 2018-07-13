#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int head=0;
char ch[100000];
void push(char x)
{
    ch[head]=x;
    head++;
   // printf("%d ",head);
}

int main ()
{
    char ar[1000],ch1[100000];
    int k,i,l;
    gets(ar);
    k=atoi(ar);
    while(k--)
    {
        gets(ch1);
        l=strlen(ch1);
        if((ch1[l-1]=='[' || ch1[0]==']' || ch1[0]==')' || ch1[l-1]=='(') || l%2!=0)
        {
        printf("No\n");
        continue;
        }
        for(i=0;i<l;i++)
        {
            if(i==0)
            {
            push(ch1[i]);
            continue;
            }
            if((ch1[i]==')' && ch[head-1]=='(') || (ch1[i]==']' && ch[head-1]=='['))
            head--;
            else
            push(ch1[i]);
        }
        if(head==0)
        printf("Yes\n");
        else
        printf("No\n");
        head=0;
    }
    return 0;
}
