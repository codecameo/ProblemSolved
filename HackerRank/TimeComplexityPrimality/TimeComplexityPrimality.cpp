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


int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        int root = sqrt(n);
        if((root*root) == n){
            cout<<"Not prime"<<endl;
            continue;
        }
        bool isFound = false;
        for(int i=2;i<root;i++){
            if(n%i == 0){
                isFound = true;
                cout<<"Not prime"<<endl;
                break;
            }
        }
        if(!isFound)
        cout<<"Prime"<<endl;
    }
    return 0;
}
