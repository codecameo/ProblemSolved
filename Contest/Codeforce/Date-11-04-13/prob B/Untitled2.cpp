#include <stdio.h>
#include <string.h>
int b[100010];
long long int a[100010],ct;
int main()
{
    memset(b,0,sizeof(b));
    int n,m,k,l[100010],r[100010],d[100010],i,j,x,y;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&l[i],&r[i],&d[i]);
    }

    for(i=0;i<k;i++)
    {
        scanf("%d %d",&x,&y);
        b[x]++;
        b[y+1]--;
    }
    for(i=1,ct=0;i<=m;i++)
    {
        ct+=b[i];
        b[i]=ct;
    }
    printf("%d %d %d %d\n",b[1],l[0],r[0],d[0]);
    for(i=1;i<=m;i++)
    {
        ct=d[i-1]*b[i];
        a[l[i-1]]+=ct;
        a[r[i]]-=ct;
        printf("%d %d %d %d %d %d\n",ct,l[i-1],r[i-1],d[i-1],a[l[i-1]],a[r[i]]);
    }
    for(i=1;i<=n;i++){
        a[i]+=a[i-1];
        if(i!=1)
        printf(" ");
    printf("%I64d",a[i]);
    }
    puts("");
    return 0;
}
