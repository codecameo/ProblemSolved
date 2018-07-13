#include <stdio.h>
#include <iostream>
using namespace std;
int table[100010];
int main()
{
    long long int n,k,i,count=0,a[100010];
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        table[a[i]]=1;
    }
    for(i=0;i<n;i++)
    {
        if(table[a[i]+k]==1)
        count++;
    }
    cout<<count<<endl;
    return 0;
}
