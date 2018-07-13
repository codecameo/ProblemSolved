#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class IceCream {
    public:
        int flavor;
        int index;

        IceCream(int flavor, int index) {
            this->flavor = flavor;
            this->index = index;
        }
};

bool compare(const IceCream &i1, const IceCream &i2){
    return i1.flavor<i2.flavor;
}

int binarySearch(int first, int last, vector<IceCream> arr, int search) {
    if(first>last) return -1;
    int mid = (first+last)/2;
    if(arr[mid].flavor == search)
        return arr[mid].index;
    else if(arr[mid].flavor>search){
        return binarySearch(first,mid-1,arr,search);
    }
    else{
        return binarySearch(mid+1,last,arr,search);
    }
}

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> m >> n;
        vector<IceCream> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr.push_back(IceCream(cost, i + 1));
        }

        for (int i = 0; i < n; i++) {
            cout<<arr[i].flavor<<' ';
        }

        cout<<'\n';

        sort(arr.begin(), arr.end(), compare);
        for (int i = 0; i < n; i++) {
            cout<<arr[i].flavor<<' ';
        }

        cout<<'\n';

        int firstIndex = 100000, secondIndex = 100000;
        for(int i = 0; i < n - 1 ; i++) {
            int search = m - arr[i].flavor;
            if(search >= arr[i].flavor) {
                int index = binarySearch( i + 1, n - 1, arr, search);
                if( index != -1 ) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;

                }
            }
        }
    }
}


