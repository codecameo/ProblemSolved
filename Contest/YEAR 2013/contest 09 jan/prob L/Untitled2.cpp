#include <stdio.h>
#include <iostream>
#define mod 1000000003
using namespace std;
int main()
{
    int tcase;
    long long int sum,a,i,n;
    cin>>tcase;
    while(tcase--)
    {
        cin>>n;
        for(i=1,a=0,sum=0;i<=n;i++)
        {
            a=a+(i*i*i);
            sum+=a;
            sum=sum%mod;
        }
        cout<<sum<<endl;
    }

    return 0;
}
