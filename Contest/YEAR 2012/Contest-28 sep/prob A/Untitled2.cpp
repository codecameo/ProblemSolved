#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 30000
using namespace std;
typedef unsigned long long ll;
int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[11][N];
ll DP(int k,int n){
	if(dp[k][n]!=-1)return dp[k][n];
	dp[k][n]=0;
	for(int i=0;i*coin[k]<=n;i++)
		{
		    dp[k][n]+=DP(k-1,n-i*coin[k]);
		}
	return dp[k][n];
}
int main(){
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<N;i++)
		dp[0][i]=1;
	int n;
	double tk;
	while(cin>>tk){
	    if(tk==0.00)
	    break;
	    n=100*tk;
		printf("%6.2lf%17llu\n",tk,DP(10,n));
	}
	return 0;
}
