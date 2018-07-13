#include <bits/stdc++.h>

using namespace std;

int getMaxMonsters(int n, int hit, int t, vector < int > h){
    int index=0;
    for(int i=0;i<t && index<n; index++){
        i += h[index]/hit;
        if(h[index]%hit!=0) i++;
    }
    return index;
}

int main() {
    int n;
    int hit;
    int t;
    cin >> n >> hit >> t;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }

    sort(h.begin(),h.end());
    int result = getMaxMonsters(n, hit, t, h);
    cout << result << endl;
    return 0;
}

