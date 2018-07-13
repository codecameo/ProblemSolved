#include <string.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int price[10001],weight[10001];
int dp[10001][400];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        int N;  cin>>N;
        for(int i=0;i<N;i++)    cin>>price[i]>>weight[i];
        int G;  cin>>G;
        int ans=0;
        for(int i=0;i<N;i++)
            for(int j=1;j<31;j++)
                if(j>=weight[i])    dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+price[i]);
                else dp[i][j]=dp[i-1][j];
        while(G--)
        {
            int x;
            cin>>x;
            ans+=dp[N-1][x];
        }
        cout<<ans<<endl;
    }
}
