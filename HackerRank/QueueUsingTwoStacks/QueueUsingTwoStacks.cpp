#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int main() {

    stack<int> s1, s2;

    int tKase;
    cin>>tKase;
    while(tKase--){
        int type, num;
        cin>>type;
        if(type == 1) {
            cin>> num;
            s1.push(num);
        }
        else if(type == 2){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            s2.pop();
        }
        else if(type == 3){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            printf("%d\n",s2.top());
        }
    }
    return 0;
}

