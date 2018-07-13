#include <stdio.h>
#include <iostream>
using namespace std;
long long int big_mod(long long int base,long long int power,long long int mod)
{
    if(power==0)    return 1;
	    else if(power%2==1)
	    {
	        long long int p1 = base % mod;
	        long long int p2 = (big_mod(base,power-1,mod))%mod;
	        return (p1*p2)%mod;
	    }
	    else if(power%2==0)
	    {
	        long long int p1 = (big_mod(base,power/2,mod))%mod;
	        return (p1*p1)%mod;
	    }
	}
int main()
{
    long long int b,p,m,ans;
    while(cin>>b>>p>>m){
    ans=big_mod(b,p,m);
    cout<<ans<<endl;
    }
    return 0;
}
