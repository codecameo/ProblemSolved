#include <stdio.h>
#include <string.h>
#define i64 long long int
#define MAX 100010
struct t
{
    int pro,sum;
}tree[4*MAX+10];
void set()
{
    int i;
    for(i=0;i<=4*MAX+10;i++)
    {
        tree[i].sum=0;
        tree[i].pro=0;
    }
}
void update(int node,int b,int e,int i,int j,long long int x)
{
    if(i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*x;
        tree[node].pro+=x;
        return;
    }
    int left=node*2,right=node*2+1,mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].pro;
}
long long int query(int node,int b,int e,int i,int j,int carry)
{
    if(i>e || j<b) return 0;
    if(b>=i && e<=j)
        return tree[node].sum+carry*(e-b+1);
    int left=node*2,right=node*2+1,mid=(b+e)/2;
    long long int p1=query(node*2,b,mid,i,j,carry+tree[node].pro);
    long long int p2=query(node*2+1,mid+1,e,i,j,carry+tree[node].pro);
    return p1+p2;
}
int main()
{
    int t,n,c,in1,in2,key,i;
    long long int up,ans;
    scanf("%d",&t);
    while(t--)
    {
        set();
        scanf("%d %d",&n,&c);
        for(i=0;i<c;i++)
        {
            scanf("%d",&key);
            if(key==0)
            {
                scanf("%d %d %d",&in1,&in2,&up);
                update(1,1,n,in1,in2,up);
            }
            else
            {
                scanf("%d %d",&in1,&in2);
                ans=query(1,1,n,in1,in2,0);
                printf("%lld\n",ans);
            }

        }


    }
    return 0;
}
