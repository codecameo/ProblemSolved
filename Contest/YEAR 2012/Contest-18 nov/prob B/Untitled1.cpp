#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
    int tcase,n,m,k,kase=1;
    double p,ans;
cin>>tcase;
while(tcase--){
cin>>n>>m>>k>>p;
ans=(1.0*(n*k))*p;
printf("Case %d: %.6lf\n",kase++,ans);
}
return 0;
}
