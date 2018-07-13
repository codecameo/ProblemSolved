#include <bits/stdc++.h>

using namespace std;

int minimumDeletions(vector < int > a){
    int INCREASE = 1, DECREASE = -1, prevState;

    int len = a.size();

    if(a[0]>a[1])
        prevState = DECREASE;
    else
        prevState = INCREASE;

    int itemDeletion = 0;

    for(int i=2;i<len;i++){
        if(a[i-1]>a[i]){
            if(prevState == DECREASE)
                itemDeletion++;
            else
                prevState = DECREASE;
        }else{
            if(prevState == INCREASE)
                itemDeletion++;
            else
                prevState = INCREASE;
        }
    }

    return itemDeletion;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    // Return the minimum number of elements to delete to make the array zigzag
    int result = minimumDeletions(a);
    cout << result << endl;
    return 0;
}

