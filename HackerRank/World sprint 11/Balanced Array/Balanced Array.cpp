#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum1=0,sum2=0;
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
       if(a_i<n/2)
        sum1+=a[a_i];
       else
        sum2+=a[a_i];
    }
    cout << abs(sum1-sum2) << endl;
    return 0;
}

