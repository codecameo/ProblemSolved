#include <stdio.h>
#include <algorithm>
using namespace std;
struct tr
{
    int l,h,val;
}tree[300005];
int a[100005];

void init(int in,int i,int j)
{
    //printf("%d %d %d\n",in,i,j);
    tree[in].l=i;
    tree[in].h=j;
    if(i==j)
    {
        tree[in].val=a[i];
        return;
    }
    int mid;
    mid=(i+j)/2;
    init(in*2,i,mid);
    init(in*2+1,mid+1,j);
    tree[in].val=tree[in*2].val+tree[in*2+1].val;
}

void set(int val,int in,int index)
{
    //printf("%d %d %d\n",index,i,j);
    if(tree[index].l==in && tree[index].h==in)
        {
            tree[index].val=0;
            return;
        }
    int res,mid=(tree[index].l+tree[index].h)/2;
    if(in>mid)
        {
            tree[index].val=-val;
            set(val,in,index*2+1);
        }
    else if(mid<=in)
        {
            tree[index].val=-val;
            set(val,in,index*2);
        }
}

void set_plus(int val,int in,int index)
{
    //printf("%d %d %d\n",index,i,j);
    if(tree[index].l==in || tree[index].h==in)
        {
            tree[index].val+=val;
            return;
        }
    int res,mid=(tree[index].l+tree[index].h)/2;
    if(in>mid)
        {
            tree[index].val+=val;
            set(val,in,index*2+1);
        }
    else if(mid<=in)
        {
            tree[index].val+=val;
            set(val,in,index*2);
        }
}

int query(int index,int i,int j)
{
    //printf("%d %d %d\n",index,i,j);
    if(tree[index].l==i && tree[index].h==j)
        return tree[index].val;
    int res,mid=(tree[index].l+tree[index].h)/2;
    if(mid>=j)
        res=query(index*2,i,j);
    else if(mid<i)
        res=query(index*2+1,i,j);
    else
        res=min(query(index*2,i,mid),query(index*2+1,mid+1,j));
    return res;
}
int main()
{
    int t,q,n,kase=1,i,x,y,j,key,money;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        init(1,1,n);
         printf("Case %d:\n",kase++);
        for(i=0;i<q;i++)
        {
            scanf("%d",&key);
            if(key==1)
            {
                scanf("%d",&x);
                set(a[x+1],x+1,1);
            }
            else if(key==2)
            {
                scanf("%d %d",&x,&money);
                set_plus(money,x+1,1);
            }
            else
            {
                scanf("%d %d",&x,&y);
            }
            for(j=1;i<=n;j++)
              printf("%d ",a[j]);
            puts("");
        }
    }

}
