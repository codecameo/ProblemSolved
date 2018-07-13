#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(){
string s[10],s1,st1,st2,st3,st4,in,temp,ar;
int n,i,a,j,k,l;
st1="0";
st2="00";
st3="000";
st4="0000";
cin>>n;
temp.clear();
getchar();
while(n--){
s1.clear();
cin>>in;
j=-1;
temp.clear();
for(i=0;i<in.size();i++){
if(in[i]!=':'){
temp=temp+in[i];
//ar=temp;
}
else{
a=temp.size();
if(a==0){
l=s1.size()+5;
temp=st4+":";
}
else if(a==1)
temp=st3+temp+":";
else if(a==2)
temp=st2+temp+":";
else if(a==3)
temp=st1+temp+":";
else if(a==4)
temp=temp+":";
s1=s1+temp;
//cout<<temp;
temp.clear();
}
}

/*for(;;){
if(s1.size()<38)
s1.replace(l,1,":0000:");
else
break;
}*/
//cout<<s1<<endl;
a=temp.size();
if(a==0)
temp=st4;
else if(a==1)
temp=st3+temp;
else if(a==2)
temp=st2+temp;
else if(a==3)
temp=st1+temp;
s1=s1+temp;
//cout<<"jd"<<endl;
for(;;){
if(s1.size()<38)
s1.replace(l-1,1,":0000:");
else
break;
}
l=s1.size();
if(l>38)
s1.erase(39,l-38);
cout<<s1<<endl;
/*s1[++j]=ar;
cout<<ar<<endl;
printf("%d\n",j);
k=j;
temp.clear();
for(i=0;i<8;i++)
{
    if(i)
    printf(":");
    cout<<s[i];
}
printf("\n");*/
}
return 0;
}
