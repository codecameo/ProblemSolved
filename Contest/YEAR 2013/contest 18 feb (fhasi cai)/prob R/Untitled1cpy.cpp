#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
const int MAXN = 200;
int a[MAXN][MAXN];
#define DEBUG
int n, m;
int dp(int i, int j){
	if(i==n && j==m) return 1;
	if(!a[i][j]){
		if(i<n && j<m) return dp(i+1, j) + dp(i, j+1);
		else if(i<n) return dp(i+1, j);
		else return dp(i, j+1);
	}else
		return 0;
}
int main(){
//#ifndef DEBUG
	//freopen("in.txt", "r", stdin);
//#endif
	int cas, line=0;
	scanf("%d", &cas);
	//printf("\n");
	while(cas--){
		memset(a, 0, sizeof(a));
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
				if(j) a[i][x] = 1;
			}
		}
		if(line++) printf("\n");
		printf("%d\n", dp(1, 1));
		/*if(cas!=0)
		printf("\n");*/
	}
	return 0;
}
