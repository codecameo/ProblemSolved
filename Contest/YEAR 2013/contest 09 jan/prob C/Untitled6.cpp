#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> m;
int main(){
int tcase,i,gd,mgd,max1,max2,a,x;
cin>>tcase;
while(tcase--){
    m.clear();
cin>>gd>>mgd;
for(i=0;i<gd;i++){
cin>>a;
m[a]=1;
}
for(i=0;i<mgd;i++){
cin>>a;
if(m[a]!=1)
m[a]=2;
}
map<int,int>::iterator it =m.end();
//x=m.size();
//cout<<x<<endl;
it--;
//cout << it->first << " => " << it->second << '\n';
if(it->second==1)
printf("Godzilla\n");
else
printf("MechaGodzilla\n");
}
return 0;
}
