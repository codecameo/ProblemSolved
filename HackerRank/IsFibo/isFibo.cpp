#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {

    map<long int, bool> m;
    m[0] = true;
    m[1] = true;
    long int c = 0, a = 0, b = 1;
    while(c<100000000000){
        c = a+b;
        m[c] = true;
        a = b;
        b = c;
    }

    int tKase;
    cin >> tKase;

    while(tkase--){
        int num;
        cin >> num;
        if(m.find(num)->second){
            cout<<"IsFibo"<<endl;
        }else{
            cout<<"IsNotFibo"<<endl;
        }
    }


    return 0;
}
