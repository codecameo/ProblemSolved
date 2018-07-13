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

using namespace std;


int main(){
    string s;
    cin >> s;
    set<int> index;
    std::set<int>::iterator it;

    int len = s.length();

    int offset = s[0]-'a'+1;
    index.insert(offset);

        //cout<<offset<<endl;

    for(int i = 1; i < len; i++){
        if(s[i-1]==s[i]){
            offset= offset+ s[i]-'a'+1;
        }
        else{
            offset = s[i]-'a'+1;
        }
        index.insert(offset);
        //cout<<offset<<endl;
    }


    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;

        //it = index.find(x);

        if(index.find(x) != index.end())

        //if(){
            cout<<"Yes"<<endl;
        //}
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
