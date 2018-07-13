#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main(){
string st;
long long int i,ar[6];
while(getline(cin,st)){
memset(ar,0,sizeof(ar));
for(i=0;i<st.size();i++)
st[i]=tolower(st[i]);
for(i=0;i<st.size();i++){
if(st[i]=='s')
ar[0]++;
if(st[i]=='e'){
ar[1]+=ar[0];
ar[3]+=ar[2];
}
else if(st[i]=='v')
ar[2]+=ar[1];
else if(st[i]=='n')
ar[4]+=ar[3];
}
cout<<ar[4]<<endl;
}
return 0;
}
