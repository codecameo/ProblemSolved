#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
priority_queue<int> mgod;
priority_queue<int> god;
int main(){
int tcase,a,i,gd,mgd,x,y;
cin>>tcase;
while(tcase--){
bool flag=true;
//printf("\n");
cin>>gd>>mgd;
for(i=0;i<gd;i++){
    cin>>a;
god.push(-a);
}
for(i=0;i<mgd;i++){
cin>>a;
mgod.push(-a);
}
/*while(!god.empty())
{
    cout<<god.top()<<endl;
    god.pop();
}*/
//cout<<god.size()<<endl;
//cout<<mgod.size()<<endl;
for(;;){
if(god.empty()){
break;
}
if(mgod.empty()){
flag=false;
break;
}
x=-god.top();
y=-mgod.top();
if(x==y || x>y)
mgod.pop();
else
god.pop();
}
if(!flag)
printf("Godzilla\n");
else
cout<<"MechaGodzilla"<<endl;
/*while(!god.empty())
{
    printf("h\n");
    cout<<god.top()<<endl;
    god.pop();
}*/
}
return 0;
}
