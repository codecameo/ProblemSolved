#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
int tcase,day,i,kase=1;
double ans;
cin>>tcase;
while(tcase--){
cin>>day;
for(i=1,ans=1;;i++){
ans*=1.0*(day-i)/(1.0*day);
//cout<<ans<<endl;
if(1-ans>=0.5000000)
break;
}
printf("Case %d: %d\n",kase++,i);
}
return 0;
}
