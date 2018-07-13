#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define i64 long long
int tes,hh,ll,cnt,prm[1100000],vis[11000000];
void init()
{
    memset(vis,0,sizeof(vis));
    for(int i=3;i<4000;i+=2)if(!vis[i])
        for(int j=i*i;j<10001000;j+=i)
            vis[j]=1;
    cnt=0;
    for(int i=3;i<10001000;i+=2)if(!vis[i])
        prm[cnt++]=i;
        printf("%d\n",cnt);
}
i64 cal(int n)
{
   // int pos=upper_bound(prm,prm+cnt,n)-prm;
    i64 res=0;
    for(int i=0,j=cnt-1;i<j;++i)
    {
        while(j>i&&prm[j]+prm[i]>n)
            --j;
        res+=j-i;
    }
    return res;
}
int main()
{
    init();
    for(int i=0;i<10;i++)
    printf("%d ",prm[i]);
    while(scanf("%d %d",&ll,&hh),ll||hh)
        printf("%lld\n",cal(hh));
    return 0;
}
