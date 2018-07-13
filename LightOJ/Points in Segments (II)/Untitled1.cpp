#include <stdio.h>
#include <algorithm>
using namespace std;
struct tr
{
    int l,h,val;
}tree[30000001];
struct reg
{
    int a,b;
} reng[50010];

void init(int in,int i,int j)
{
    tree[in].val=0;
    tree[in].l=i;
    tree[in].h=j;
    if(i==j)
    {
        tree[in].val=0;
        return;
    }
    int mid;
    mid=(i+j)/2;
    init(in*2,i,mid);
    init(in*2+1,mid+1,j);
    //tree[in].val=tree[in*2].val+tree[in*2+1].val;
}

void set(int index,int st,int end)
{
    if(tree[index].l == tree[index].h || (tree[index].l>=st && tree[index].h<=end ))
        {
            tree[index].val++;
            return;
        }
    int mid=(tree[index].l+tree[index].h)/2;
    if(mid>=end)
            set(index*2,st,end);
    else if(mid<st)
        set(index*2+1,st,end);
    else if(mid>=st && mid<end)
    {
        set(index*2,st,mid);
        set(index*2+1,mid+1,end);
    }
}

int query(int i,int index,int sum)
{
    //printf("%d %d %d %d\n",tree[index].l,tree[index].h,i);
    sum=sum+tree[index].val;
    if(tree[index].l==i && tree[index].h==i)
        {
            tree[index].val++;
            return sum;
        }
    int res,mid=(tree[index].l+tree[index].h)/2;
    if(mid>=i)
        {
            tree[index*2+1].val++;
            res=query(i,index*2,sum);
        }
    else
        res=query(i,index*2+1,sum);
    return res;
}
int main()
{
    int t,q,n,kase=1,i,x,y,j,k,ans,mx;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&reng[i].a,&reng[i].b);
            mx=max(reng[i].b,mx);
        }
        init(0,1,mx);
        for(i=1;i<=n;i++)
        {
            x=reng[i].a;
            y=reng[i].b;
            set(0,x,y);
        }
        for(i=1;i<=q;i++)
        {
            scanf("%d",&x);
            if(x>mx)
            printf("0\n");
            else
            printf("%d\n",query(x,1,0));
        }
    }
return 0;
}
