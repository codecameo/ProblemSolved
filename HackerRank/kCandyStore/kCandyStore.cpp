#include <iostream>

using namespace std;
int dp[1000][1000];
int calDp(int n, int r){
    if(dp[n][r] != 0) return dp[n][r];
    if(n==r) return dp[n][r] = 1;
    if(r == 0) return dp[n][r] = 1;
    return dp[n][r] = (calDp(n-1, r-1) + calDp(n-1, r))%1000000000;
}

int solve(int n, int k) {
    return calDp(n,k);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int result = solve(n + k -1, k);
        cout<<result<<endl;
    }
    return 0;
}

