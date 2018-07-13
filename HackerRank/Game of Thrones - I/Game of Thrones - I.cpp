#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool ch[27];

int main() {

    int flag = 0;
    string s;
    cin>>s;
    int len = s.length();

    for(int i=0;i<len;i++){
        char c = s.at(i);
        ch[c - 'a']= !ch[c - 'a'];
    }

    for(int i=0;i<27;i++){
        if(ch[i]){
            if(flag == 0)
                flag++;
            else{
                flag++;
                break;
            }
        }
    }

    if(flag==2)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
