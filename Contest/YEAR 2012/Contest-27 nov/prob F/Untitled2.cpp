#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main(){
long long int i,a,b,x,y,mn,k;
    cin>>a>>b>>x>>y;
    k=__gcd(x,y);
    x/=k;
    y/=k;
mn=min(a/x,b/y);
cout<<x*mn<<" "<<y*mn<<endl;
//}
return 0;
}
