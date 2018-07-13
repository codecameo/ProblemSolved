#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
int dp[210][210],ar[210][210],m,n;
int DP(int x,int y,int req)
{
    if(x==n && y==m && req>=0)
    {
        return dp[x][y]=1;
    }
    else if(req==0)
    return 0;
    if(x>n || y>m)
    return 0;
    if(ar[x][y]==1)
    return 0;
    if(ar[x][y]==0)
    return dp[x][y]=DP(x+1,y,req-1)+DP(x,y+1,req-1);
}

int main(){
	int cas, line=0;
	scanf("%d", &cas);
	while(cas--){
		memset(ar, 0, sizeof(ar));
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &n, &m);
		int i, j;
		string data;
		getchar();
		for(i=1; i<=n; i++){
			getline(cin,data);
			istringstream sin(data);
			//cout<<sin<<endl;
			int x;
			for(j=0; sin>>x; j++){
			    //cout<<sin<<" "<<x<<" "<<j<<endl;
				if(j) ar[i][x] = 1;
			}
		}
		if(line++) printf("\n");
		int b=(n-1)+(m-1);
		printf("%d\n", DP(1,1,b));
		/*if(cas!=0)
		printf("\n");*/
	}
	return 0;
}
