#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int coin[1000000];
int ans[1000000];
int dp(int tk)
{
    int i,j;
    if(tk<0)
    return 0;
    if(tk==0)
    return 1;
    if(ans[tk]!=0)
    return ans[tk];

    for(i=0;i<5;i++)
    {
        //if(dp(tk-coin[i]))
        for(j=coin[i];j<=tk;j++)
        ans[j]+=dp(j-coin[i+1]);
        //return ans[tk];
    }

}
int main()
{
    int cent,j,k,n,i,c[60],m,kase;
    memset(ans,0,sizeof(ans));
    //dp(7489);
    cin>>kase;
    while(kase--)
    {
        scanf("%d %d",&n,&cent);
        memset(ans,0,sizeof(ans));
        //dp(cent);
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
        }
        for(i=0,k=0;i<n;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                coin[k++]=c[i];
            }
        }
        dp(cent);
        cout<<ans[cent]<<endl;
    }

    return 0;
}
