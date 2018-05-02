#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


int main() {

    map<string, int> sparse;
    int tKase;
    cin >> tKase;
    while(tKase--){
        string word;
        cin >> word;
        int count = sparse[word];
        count ++;
        sparse[word] = count;
    }

    cin >> tKase;
    while(tKase--){
        string word;
        cin >> word;
        cout << sparse[word] << endl;
    }

    return 0;
}
