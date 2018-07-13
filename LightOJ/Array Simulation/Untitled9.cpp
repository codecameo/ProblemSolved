#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n,ar[150];
void add(int x)
{
    int i;
    for(i=0;i<n;i++)
    ar[i]+=x;
}
void mul(int x)
{
    int i;
    for(i=0;i<n;i++)
    ar[i]*=x;
}
void dev(int x)
{
    int i;
    for(i=0;i<n;i++)
    ar[i]/=x;
}
void swp(int x,int y)
{
    swap(ar[x],ar[y]);
}
void rev()
{
    int i,j;
    for(i=0,j=n-1;i<j;i++,j--)
    swap(ar[i],ar[j]);
}
int main()
{
    int t,kase=1,op,x,i,z;
    char c;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",kase++);
        scanf("%d %d",&n,&op);
        for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
        //puts("gf");
        getchar();
        for(i=0;i<op;i++)
        {
            scanf("%c",&c);
            if(c=='S')
            {
               cin>>x;
               add(x);
            }
            else if(c=='M')
            {
               cin>>x;
               mul(x);
            }
            else if(c=='D')
            {
               cin>>x;
               dev(x);
            }
            else if(c=='P')
            {
               cin>>x>>z;
               swp(x,z);
            }
            else if(c=='R')
            {
               rev();
            }
            getchar();
        }
        for(i=0;i<n;i++)
        {
            if(i)
            printf(" ");
            printf("%d",ar[i]);
        }
        puts("");
    }
}
