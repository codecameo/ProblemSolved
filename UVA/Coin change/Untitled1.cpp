#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int coin[]={1,5,10,25,50};
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
        ans[j]+=dp(j-coin[i]);
        //return ans[tk];
    }

}
int main()
{
    int cent;
    memset(ans,0,sizeof(ans));
    dp(7489);
    while(scanf("%d",&cent)!=EOF)
    {
        //memset(ans,0,sizeof(ans));
        //dp(cent);
        cout<<ans[cent]<<endl;
    }

    return 0;
}
