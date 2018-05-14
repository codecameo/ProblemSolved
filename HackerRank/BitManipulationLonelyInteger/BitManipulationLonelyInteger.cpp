#include <bits/stdc++.h>

using namespace std;

int bitXor(int x, int y) {
    int a = x & y;
    int b = ~x & ~y;
    int z = ~a & ~b;
    return z;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    bool found;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        found = false;
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int y = a[j];
            if(bitXor(x,y)==0){
                found = true;
                break;
            }
        }
        if(!found){
            cout<<a[i]<<endl;
            return 0;
        }
    }

    return 0;
}

