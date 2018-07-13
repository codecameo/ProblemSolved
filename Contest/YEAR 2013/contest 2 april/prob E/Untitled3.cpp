#include <stdio.h>
#include <vector>
#include <string.h>
#define MAX 100009
#define pb push_back
using namespace std;
int n,mx,ar[MAX];
long long int ans;
vector <int>v[MAX];
void init(){
	memset(ar,0,sizeof(ar));
	for(int i=1;i<=mx;i++){
	    if(v[i].size()!=0)
		v[i].clear();
	}
	ans=0;
}
int dfs(int s)
{
    int i,res=0;
    //printf("%ds\n",s);
    if(v[s].size()==0)
    return 0;
    for(i=0;i<v[s].size();i++)
    {
        res+=dfs(v[s][i]);
        //ar[s]+=res;
        //printf("%ds %dr\n",s,res);
    }
    ar[s]+=res;
    //printf("%d %d\n",s,ar[s]+v[s].size());
    return ar[s]=v[s].size()+ar[s];
}


int main()
{
    int t,i,s,d,card,j,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        mx=-1;
        init();
        scanf("%d",&n);
        card=n-1;
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&s,&d);
            v[s].pb(d);
            if(d>mx)
            mx=d;
        }
        dfs(1);
       /* for(i=1;i<=mx;i++){
        for(j=0;j<v[i].size();j++)
        printf("%d ",v[i][j]);
        puts("");
        }*/
        ans=0;
        for(i=2,j=0;i<mx;i++,j++)
        {
             s=ar[i]+2+j;
             //printf("%d-> %d %d %d %d\n",i,j,v[i].size(),n-s,s);
             ans+=(long long int)(n-s);
        }
        //if(ans<0)
        //ans=0;
        printf("Case %d: %d %lld\n",kase++,card,ans);
    }
    return 0;
}
