#include <stdio.h>
#include <iostream>
using namespace std;
struct min{
    int x,val;
   bool operator < ( const min &p ) const
    {
        return val < p.val;
    }
}num1[1000000];
struct max{
    int x,val;
   bool operator <( const max &p ) const
    {
        return p.val<val;
    }
}num2[1000000];


int main(){
int n,i,flag,num;
cin>>n;
if(n==2)
{
    cout<<"-1"<<endl;
    return 0;
}
for(i=0,flag=0;i<n;i++){
cin>>num;
num1[i].x=i;
num1[i].val=num;
num2[i].x=i;
num2[i].val=num;
}
for(i=0;i<n;i++)
cout<<num1[i].val<<" ";
cout<<endl;
for(i=0;i<n;i++)
cout<<num2[i].val<<" ";
return 0;
if(flag==0){
cout<<"-1"<<endl;
return 0;
}
/*for(i=n;i>1;i--)
{
    if(num[0]!=num[i])
    {
        cout<<"1 "<<i<<endl;
        break;
    }
}
return 0;*/
}
