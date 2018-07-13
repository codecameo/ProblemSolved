#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int main(){

int per,tcase,n;
double pro,res;
cin>>tcase;
while(tcase--){
    res=1;
cin>>per>>pro>>n;
res=pow((1.0*1-pro),n-1)*pro;
if(res==0){
printf("0.0000\n");
continue;
}
res/=1.0*(1.0*1-pow((1.0*1-pro),per));
printf("%.4lf\n",res);
}
return 0;
}
