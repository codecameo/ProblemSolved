#include <stdio.h>
#include <string.h>
int left=100,right=0,ar[110];
int tree(int pos,int n)
{
    //printf("%dp\n",pos);
    if(n==-1)
    return 0;
    int a,b;
    if(pos<left) left=pos;
    if(pos>right) right=pos;
    //printf("a: ");
    scanf("%d",&a);
    if(a!=-1)
    ar[pos-1]+=a;
    tree(pos-1,a);
   // printf("b: ");
    scanf("%d",&b);
    if(b!=-1)
    ar[pos+1]+=b;
    tree(pos+1,b);
}
int main()
{
    int ps,n,i,kase=1;
    while(scanf("%d",&n))
    {
        memset(ar,0,sizeof(ar));
        if(n==-1)
        break;
        ps=50;
        ar[50]+=n;
        tree(ps,n);
        printf("Case %d:\n",kase++);
        for(i=left;i<right;i++)
        printf("%d ",ar[i]);
        printf("%d\n\n",ar[right]);
        left=100;
        right=0;
    }
    return 0;
}
