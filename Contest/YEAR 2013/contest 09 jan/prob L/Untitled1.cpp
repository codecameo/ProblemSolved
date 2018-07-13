#include <stdio.h>
#include <iostream>
#define mod 1000000003
using namespace std;
long long int quebe(long long int n)
{
    long long int ans;
    //ans=((((n*n)%mod)*((n+1)*(n+1))%mod)/4)%mod;
    //cout<<ans<<endl;
    ans=(n*n)/4;
    ans=ans*(n+1)*(n+1);
    return ans;
}
int main()
{
    int tcase;
    long long int n,sum,i;
    cin>>tcase;
    while(tcase--)
    {
        cin>>n;
        for(i=1,sum=0;i<=n;i++)
        {
            sum+=quebe(i);
            sum=sum%mod;
        }
        cout<<sum<<endl;
    }
    return 0;
}
