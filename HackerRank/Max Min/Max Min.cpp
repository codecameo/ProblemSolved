#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    sort(list,list+N);

    int i, j = K-1;

    for(int i=0;j<N;i++,j++){
        int sub = list[j]-list[i];
        unfairness = min(unfairness,sub);
    }

    cout << unfairness << "\n";
    return 0;
}
