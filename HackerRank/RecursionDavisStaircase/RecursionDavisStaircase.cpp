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
int num[37];
int getNum(int curHeight){
    if(num[curHeight] != 0) return num[curHeight];
    return num[curHeight] = getNum(curHeight -1) + getNum(curHeight -2) + getNum(curHeight -3);
}

int main(){
    int s;
    cin >> s;
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        cout<<getNum(n)<<endl;
    }
    return 0;
}
