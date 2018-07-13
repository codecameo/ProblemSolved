#include <bits/stdc++.h>
#include<math.h>

using namespace std;

int shortestTightArray(int a, int b, int c){
    // Complete this function

    return abs(b-a)+abs(b-c)+1;

}

int main() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    int result = shortestTightArray(a, b, c);
    cout << result << endl;
    return 0;
}

