#include <stdio.h>
#include <string.h>
int a[100],sv_l,sv_r;
void call(int n,int pos)
{
    int x,y;
    if(n!=-1)
    {
        a[pos]+=n;
        scanf("%d",&x);
        call(x,pos-1);
        if(pos>sv_l)    sv_l=pos;
        scanf("%d",&y);
        call(y,pos+1);
        if(pos<sv_r)    sv_r=pos;
    }
}
void reset()
{
    sv_l=40;
    sv_r=40;
    memset(a,0,sizeof(a));
}
int main()
{
    int n,CASE=0;
    while(scanf("%d",&n)&& n!=-1)
    {
        reset();
        call(n,40);
        //printf("%d %d ",sv_l,sv_r);
        printf("Case %d:\n%d",++CASE,a[sv_r]);
        for(sv_r=sv_r+1;sv_r<=sv_l;sv_r++)  printf(" %d",a[sv_r]);
        puts("");puts("");
    }
}
