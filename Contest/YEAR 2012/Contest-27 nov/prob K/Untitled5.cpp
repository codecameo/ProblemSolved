//#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(){
long long int tcase,sec,sq1,ans,num,row,com,kase=1;
cin>>tcase;
while(tcase--){
cin>>sec;
sq1=ceil(sqrt(sec));
num=(sq1-1)*(sq1-1);
ans=sec-num;
if(ans==sq1){
cout<<"Case "<<kase++<<":"<<" "<<ans<<" "<<ans<<endl;
continue;
}
if((sq1-1)%2==0){
if(sec-num<sq1){
row=sq1;
com=sec-num;
}
else{
com=sq1;
row=(sq1*sq1)-sec+1;
}
cout<<"Case "<<kase++<<":"<<" "<<row<<" "<<com<<endl;
}
else{
if(sec-num<sq1){
com=sq1;
row=sec-num;
}
else{
row=sq1;
com=(sq1*sq1)-sec+1;
}
cout<<"Case "<<kase++<<":"<<" "<<row<<" "<<com<<endl;
}
}
return 0;
}
