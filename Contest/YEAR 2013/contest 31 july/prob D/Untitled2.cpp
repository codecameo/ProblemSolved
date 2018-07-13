#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;
int i,j,k,l,stp,cnt,pre[30][300055],sor[300055],ans,mx,u,len,x,y;
char c[300055],d[300055];
struct entry
{
    int nr[2],pos;
}st[300055];
bool cmp(entry a,entry b)
{
    if(a.nr[0]==b.nr[0])
    {
        return a.nr[1]<b.nr[1];
    }
    else
    {
        return a.nr[0]<b.nr[0];
    }
}
void suffix()
{
    for(i=0;i<l;i++)
    {
        pre[0][i]=c[i]-'#';
    }
    for(stp=cnt=1;cnt/2<l;stp++,cnt*=2)
    {
        for(i=0;i<l;i++)
        {
            st[i].nr[0]=pre[stp-1][i];
            if(i+cnt<l)
            {
                st[i].nr[1]=pre[stp-1][i+cnt];
            }
            else
            {
                st[i].nr[1]=-1;
            }
            st[i].pos=i;
        }
        sort(st,st+l,cmp);
        for(i=0;i<l;i++)
        {
            if((i>0)&&(st[i].nr[0]==st[i-1].nr[0])&&(st[i].nr[1]==st[i-1].nr[1]))
            {
                pre[stp][st[i].pos]=pre[stp][st[i-1].pos];
            }
            else
            {
                pre[stp][st[i].pos]=i;
            }
        }
    }
    for(i=0;i<l;i++)
    {
        sor[pre[stp-1][i]]=i;
    }
}
int lcp(int x,int y)
{
    int ret=0;
    if(x==y)
    {
        return l-x;
    }
    for(k=stp-1;(k>=0)&&(x<l)&&(y<l);k--)
    {
        if(pre[k][x]==pre[k][y])
        {
            x+=(1<<k);
            y+=(1<<k);
            ret+=(1<<k);
        }
    }
    return ret;
}
int main()
{
    while(scanf("%d%s%s",&len,c,d)!=EOF)
    {
        strcat(c,"#");
        strcat(c,d);
        l=strlen(c);
        suffix();
        mx=0;
        ans=0;
        for(i=0;i<l-1;i++)
        {
            u=lcp(sor[i],sor[i+1]);
            y=max(sor[i],sor[i+1]);
            x=min(sor[i],sor[i+1]);
            if((mx<u)&&(len<y)&&(len>x))
            {
                printf("%d %d\n",u,sor[i]);
                mx=u;
                ans=sor[i];
            }
        }
        for(i=ans;i<ans+mx;i++)
        {
            printf("%c",c[i]);
        }
        printf("\n");
    }
    return 0;
}
