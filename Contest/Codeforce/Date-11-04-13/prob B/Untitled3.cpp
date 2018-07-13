#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int b[100010];
long long int a[100010],ct,num[100010],l[100010],r[100010],d[100010];
int main()
{
    long long int n,m,k,i,j,x,y;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%I64d %I64d %I64d",&l[i],&r[i],&d[i]);
    }

    for(i=0;i<k;i++)
    {
        scanf("%I64d %I64d",&x,&y);
        b[x]++;
        b[y+1]--;
    }
    for(i=1,ct=0;i<=m;i++)
    {
        ct+=b[i];
        b[i]=ct;
    }
    for(i=1;i<=m;i++)
    {
        ct=d[i-1]*b[i];
        num[l[i-1]]+=ct;
        num[r[i-1]+1]-=ct;
    }
    for(i=1;i<=n;i++)
    {
        num[i]+=num[i-1];
        if(i!=1)
        printf(" ");
    printf("%I64d",a[i]+num[i]);
    }
    puts("");
    return 0;
}
