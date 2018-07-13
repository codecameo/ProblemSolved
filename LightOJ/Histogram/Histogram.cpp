#include <stdio.h>
#include <algorithm>
using namespace std;
int a[30005],maxi,index;
struct tr
{
    int l,h,rec,val;
}tree[90005];

void init(int in,int i,int j)
{
    //printf("%d %d %d\n",in,i,j);
    tree[in].l=i;
    tree[in].h=j;
    if(i==j)
    {
        tree[in].val=a[i];
        tree[in].rec=a[i];
        return;
    }
    int mid;
    mid=(i+j)/2;
    init(in*2,i,mid);
    init(in*2+1,mid+1,j);
    tree[in].val=min(tree[in*2].val,tree[in*2+1].val);
    tree[in].rec=(j+1-i)*tree[in].val;
    if(maxi<tree[in].rec)
      {
          index=in;
          maxi=tree[in].rec;
      }
}
void query()
{
    int in=index+1;
    while(1)
    {
        if(tree[in].l<tree[in-1].h)
        break;
        if(((tree[in].h+1-tree[index].l)*tree[in].val)<maxi)
        {
            maxi=((tree[in].h+1-tree[index].l)*tree[in].val);
        }
    }

}
int main()
{
    int t,kase,i,n;
    scanf("%d",&t);
    while(t--)
    {
        maxi=-1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        init(1,1,n);
         printf("%d %d\n",maxi,index);


    }
    return 0;
}
