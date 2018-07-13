#include <stdio.h>
#include <iostream>
using namespace std;
struct st{
int x,y;
}st1,st2;
int main(){
int n,arh=0,afl=0,brh=0,bfl=0,ser;
cin>>n;
while(n--){
cin>>ser;
if(ser==1){
cin>>st1.x>>st1.y;
arh+=st1.x;
afl+=st1.y;
}
if(ser==2){
cin>>st2.x>>st2.y;
brh+=st2.x;
bfl+=st2.y;
}
}
if(arh>=afl)
cout<<"LIVE"<<endl;
else
cout<<"DEAD"<<endl;
if(brh>=bfl)
cout<<"LIVE"<<endl;
else
cout<<"DEAD"<<endl;


return 0;
}
