#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
    int first[27] = {0}, second[27] = {0};
    int len = a.length();
    for(int i=0;i<len;i++){
        char x = a[i];
        first[x-'a']++;
    }
    len = b.length();
    for(int i=0;i<len;i++){
        char x = b[i];
        second[x-'a']++;
    }

    int count=0;
    for(int i =0;i<=26;i++){
        count+=abs(first[i]-second[i]);
    }
    return count;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
