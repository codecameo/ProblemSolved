#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    int n, m;
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> m >> n;
        map<int, int> freqMap, indexMap;
        vector<int> arr[50001];
        vector<int> iceCost;

        int count = 0;
        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            iceCost.push_back(cost);
            freqMap[cost]++;
            int index;
            if(freqMap[cost] == 1){
                index = ++count;
                indexMap[cost] = index;
            }else{
                index = indexMap[cost];
            }
            arr[index].push_back(i);
        }

        for (int i = 0; i < iceCost.size(); i++) {
            int cost = iceCost[i];
            freqMap[cost]--;
            int search = m - cost;
            if(freqMap[search] > 0){
                int index1 = indexMap[cost];
                int index2 = indexMap[search];
                int res2 = index1 == index2? arr[index1][1] : arr[index2][0];
                int res1 = arr[index1][0];
                res2++;
                res1++;
                cout << min(res1, res2) <<" "<<max(res1, res2)<<endl;
                break;
            }
            freqMap[cost]++;
        }
    }
}
