#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000007
ll num[100005];
int main()
{
    ll a,k,c,i,n,sum;
    int kase = 1;
    int t;
    cin>>t;
    while(kase<=t)
    {
        cin>>k>>c>>n>>a;
        num[0] = a;
        for(i=1;i<n;i++)
        {
            num[i] = (k*num[i-1] + c)%mod;
        }
        sort(num,num+n);
        sum = 0;
        for(i=1;i<n;i++)

         sum += (num[i]-num[i-1])*i*(n-i);

        printf("Case %d: %lld\n",kase++,sum);
    }
    return 0;
}
