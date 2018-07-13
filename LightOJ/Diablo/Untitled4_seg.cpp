#include <stdio.h>
#include <algorithm>
using namespace std;
struct tr
{
    int l,h,val;
}tree[550015];
int a[280005],que[50010];

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
    int t,q,n,kase=1,i,x,y,j,k,ans,count;
    char key[4];
    scanf("%d",&t);
    while(t--)
    {
        int sch;
        k=-1;
        scanf("%d %d",&n,&q);
        sch=n;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        //init(1,1,n);
         getchar();
        for(i=0;i<q;i++)
        {
           // getchar();
            scanf("%s",key);
            //key=getchar();
            if(key[0]=='a')
            {
                scanf("%d",&a[++n]);
                //init(1,1,n);
                sch++;
            }
            else
            {
                //printf("%c %d\n",key,sch);
                scanf("%d",&x);
                //printf("%d %d\n",x,sch);
                if(sch<x)
                    que[++k]=-1;
                else
                    {
                        sch--;
                        que[++k]=x;
                    }
            }
        }
        printf("Case %d:\n",kase++);
        init(1,1,n);
        //for(j=1;j<=2*n;j++)
          //  printf("%d ",tree[j].val);
        //puts("");
        for(i=0;i<=k;i++)
        {
            if(que[i]==-1)
            puts("none");
            else
            {
                ans=query(que[i],1,0);
                printf("%d ",ans);
                if(ans!=0)
                for(j=que[i]+1,count=0;;j++)
                {
                    if(a[j]!=-1)
                    count++;
                    if(count==ans)
                    {
                        printf("%d\n",a[j]);
                        a[j]=-1;
                        break;
                    }
                }
                else
                {
                    printf("%d\n",a[que[i]]);
                    a[que[i]]=-1;
                }
            }
            /*for(j=1;j<=2*n;j++)
                printf("%d ",tree[j].val);
            puts("");*/
        }
    }
return 0;
}
