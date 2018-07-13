#include <stdio.h>
#include <iostream>
#include <algorithm>
int ar1[10000010],ar2[10000010];
using namespace std;
int main(){
int tcase,i,gd,mgd,max1,max2;
cin>>tcase;
while(tcase--){
cin>>gd>>mgd;
for(i=0;i<gd;i++){
cin>>ar1[i];
}
for(i=0;i<mgd;i++){
cin>>ar2[i];
}
sort(ar1,ar1+gd);
sort(ar2,ar2+mgd);
if(ar1[gd-1]==ar2[mgd-1]|| ar1[gd-1]>ar2[mgd-1])
printf("Godzilla\n");
else
printf("MechaGodzilla\n");
}
return 0;
}
