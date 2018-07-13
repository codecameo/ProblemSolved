#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
string s[10],s1[10],st1,st2,st3,st4,in,temp,ar;
int n,i,a,j,k;
st1="0";
st2="00";
st3="000";
st4="0000";
cin>>n;
temp.clear();
getchar();
while(n--){
cin>>in;
j=-1;
for(i=0;i<in.size();i++){
if(in[i]!=':'){
temp=temp+in[i];
ar=temp;
}
else if(temp.size()!=0 && in[i]==':'){
s1[++j]=temp;
cout<<temp<<endl;
temp.clear();
}
}
s1[++j]=ar;
cout<<ar<<endl;
printf("%d\n",j);
k=j;
temp.clear();
j=0;
for(i=0;i<in.size();i++){
if(in[i]!=':'){
temp=temp+in[i];
ar=temp;
}
else{
a=temp.size();
if(a==0)
{
  k=7-k;
  for(i=0;i<k;i++)
  s[j++]=st4;
}
else if(a==1)
s[j++]=st3+temp;
else if(a==2)
s[j++]=st2+temp;
else if(a==3)
s[j++]=st1+temp;
else if(a==4)
s[j++]=temp;
temp.clear();
}
}
a=ar.size();
if(a==0)
s[j++]=st4;
else if(a==1)
s[j++]=st3+temp;
else if(a==2)
s[j++]=st2+temp;
else if(a==3)
s[j++]=st1+temp;
else if(a==4)
s[j++]=temp;
//printf("j\n");
for(i=0;i<8;i++)
{
    if(i)
    printf(":");
    cout<<s[i];
}
printf("\n");
}
return 0;
}
