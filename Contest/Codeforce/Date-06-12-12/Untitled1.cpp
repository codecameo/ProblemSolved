#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int a,i,ans,n,max=-1;
    cin>>n>>a;
    ans=n xor a;
    cout<<ans<<endl;
    return 0;
    for(i=0;i<n;i++){
      cin>>a;
       if(i)
       ans=ans ^ a;
       if(!i)
       ans=a;
       if(ans>max)
       max=ans;
    }
    cout<<max<<endl;
    return 0;
}
