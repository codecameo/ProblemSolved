#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string reverseStr(int x){
    string num;
    while(x/10!=0){
        int n = x%10;
        num += '0'+n;
        x=x/10;
    }
    num+='0'+ x%10;
    return num;
}

string encoding(string encode){

    int len = encode.size();
    string s;
    for(int i=len-1;i>=0;i--){
        int n = encode.at(i);
        cout<<n <<' '<<reverseStr(n)<<endl;
        s+=reverseStr(n);
    }
    return s;
}

int main(){
    string s;
    cout<<encoding("Hacker Rank");
}
