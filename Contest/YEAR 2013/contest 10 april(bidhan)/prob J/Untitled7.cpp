#include <stdio.h>
#include <vector>
#define pb push_back
using namespace std;
vector<int>v[1060];
int s,n;
int main()
{
    int i,j,k,vag,xr,min,m;
    scanf("%d %d",&n,&s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&k);
        for(j=0,xr=0;j<k;j++)
        {
            scanf("%d",&vag);
            v[vag].pb(i);
        }
    }
    for(i=0,min=999999;i<n;i++)
    {
        if(min>v[i].size())
        {
            min=v[i].size();
            m=i;
        }
    }
    printf("%d\n",v[m].size());
    for(i=0;i<v[m].size();i++){
    if(i)
    printf(" ");
    printf("%d",v[m][i]);
    }
return 0;
}
