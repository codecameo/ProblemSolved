#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 100009
#define pb push_back
using namespace std;
int n,mx,ar[MAX],c;
long long int ans;
vector <int>v[MAX];
void init(){
    int i;
	memset(ar,-1,sizeof(ar));
	for(i=1;i<=n;i++)
		v[i].clear();
	ans=0;
	mx=-1;
	c=0;
}
int dfs(int s)
{
    int i,res=0;
    ar[s]=0;
    c++;
    if(v[s].size()==0)
    return 0;
    for(i=0;i<v[s].size();i++)
        res+=dfs(v[s][i]);
    ar[s]+=res;
    return ar[s]=v[s].size()+ar[s];
}
int main()
{
    int t,i,s,d,card,j,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        card=n-1;
        init();
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&s,&d);
            v[s].pb(d);
            if(d>mx)
            mx=d;
        }
        dfs(1);
        ans=0;
        for(i=2,j=0;i<=mx;i++,j++)
        {
            if(ar[i]<0){
                j--;
            continue;
            }
             s=ar[i]+2+j;
             ans+=(long long int)(c-s);
        }
        printf("Case %d: %d %lld\n",kase++,card,ans);
    }
    return 0;
}
