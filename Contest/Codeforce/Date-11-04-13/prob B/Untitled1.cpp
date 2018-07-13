#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long int b[100010];
long long int a[100010],ct,p[100010];
int main()
{
    //memset(b,0,sizeof(b));
    //memset(p,0,sizeof(p));
    long long int n,m,k,l[100010],r[100010],d[100010],i,j,x,y;
    scanf("%I64d %I64d %I64d",&n,&m,&k);
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
        p[l[i-1]]+=ct;
        if(p[r[i-1]+1]<=n)
        p[r[i-1]+1]-=ct;
    }
    for(i=1;i<=n;i++)
    {
        p[i]+=p[i-1];
        if(i!=1)
        printf(" ");
    printf("%I64d",a[i]+p[i]);
    }
    puts("");
    return 0;
}
