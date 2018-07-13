#include <stdio.h>
#include <algorithm>
using namespace std;
struct tr
{
    int l,h,val,leaf;
}tree[550015];
int a[280005];

void init(int in,int i,int j)
{
    tree[in].l=i;
    tree[in].h=j;
    if(i==j)
        return;
    int mid;
    mid=(i+j)/2;
    init(in*2,i,mid);
    init(in*2+1,mid+1,j);
}

void add(int index,int ds,int val)
{
    if(tree[index].l==tree[index].h)
    {
            tree[index].val=val;
            tree[index].leaf=1;
            return;
    }
    int mid=(tree[index].l+tree[index].h)/2;
    if(mid>=ds)
        add(index*2,ds,val);
    else
        add(index*2+1,ds,val);
    tree[index].leaf=tree[index*2].leaf+tree[index*2+1].leaf;
}
void update(int index,int leaf,int lf,int val)
{
    if(tree[index].l==tree[index].h)
        {
            tree[index].val=val;
            tree[index].leaf=lf;
            return;
        }
    int mid=(tree[index].l+tree[index].h)/2;
    if(leaf<=tree[index*2].leaf)
        update(index*2,leaf,lf,val);
    else
        update(index*2+1,leaf-tree[index*2].leaf,lf,val);
    tree[index].leaf=tree[index*2].leaf+tree[index*2+1].leaf;
}
int query(int index,int leaf)
{
    if(tree[index].l==tree[index].h)
        return tree[index].val;
    int res,mid=(tree[index].l+tree[index].h)/2;
    if(leaf<=tree[index*2].leaf)
        res=query(index*2,leaf);
    else
        res=query(index*2+1,leaf-tree[index*2].leaf);
    return res;
}

int main()
{
    int t,q,n,kase=1,i,x,y,j,k,node;
    char key[4];
    scanf("%d",&t);
    while(t--)
    {
        int sch=0;
        k=-1;
        scanf("%d %d",&n,&q);
        init(1,1,n+q);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            add(1,i,a[i]);
        }
        node=n;
         getchar();
         printf("Case %d:\n",kase++);
        for(i=0;i<q;i++)
        {
            scanf("%s",key);
            if(key[0]=='a')
            {
                scanf("%d",&a[++n]);
                node++;
                add(1,n,a[n]);
            }
            else
            {
                scanf("%d",&x);
                if(node<x)
                {
                    puts("none");
                    continue;
                }
                node--;
                printf("%d\n",query(1,x));
                update(1,x,0,-1);
            }
        }
    }
return 0;
}
