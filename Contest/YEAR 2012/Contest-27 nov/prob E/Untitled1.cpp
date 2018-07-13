#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int tcase,i,count=0;
    double point[100010],st;
    while(cin>>tcase){
    count=1;
    for(i=0;i<tcase;i++){
    cin>>point[i];
    }
    st=point[0];
    for(i=1;i<tcase;i++){
    if(st+1.0<=point[i]){
    count++;
    st=point[i];
    }
    }
    cout<<count<<endl;
    }
    return 0;
}
