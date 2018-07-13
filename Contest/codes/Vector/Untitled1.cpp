#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int main(){
int i;
vector<int>v1(10,9);
for(i=0;i<10;i++){
v1.push_back(i+1);
}
/*vector<int> v(20);
 for(int i = 0; i < 20; i++) {
      v[i] = i+1;
 }
 v.resize(25);
 for(int i = 20; i < 25; i++) {
      v.push_back(i*2); // Writes to elements with indices [25..30), not [20..25) ! <
 }*/
vector<int>v3=v1;
v3.reserve(20);
for(i=0;i<20;i++){
cout<<v3[i]<<endl;
}
return 0;
}
