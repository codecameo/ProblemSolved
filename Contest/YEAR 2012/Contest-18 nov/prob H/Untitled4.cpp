#include<cstdio>
#include<iostream>
#include<cstring>
#define ll unsigned long long
using namespace std;
const ll mod = 1000000007;
ll mypow(ll n, ll k) {
	ll ans = 1;
	for(;k>0;k/=2) {
		if(k&1) ans = (ans * n) % mod;
		printf("%lld\n",k&1);
		n = (n * n)%mod;
		printf("%lld %lld %lld\n",ans,k,n);
	}
	return ans;
}
int main()
{
	ll n;
	int T;
	cin>>T;
	int k = 0;
	while(T--) {
		cin >> n;
		cout << "Case #" << ++k << ": " << (n*mypow(2, n - 1)) % mod << endl;
	}
	return 0;
}
