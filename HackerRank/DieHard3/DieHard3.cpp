#include <iostream>

using namespace std;

// Complete the solve function below.
string solve(int a, int b, int c) {
    if(a>b) swap(a,b);
    if(c>b) return "NO";
    while(b%a!=0){
        int s = b%a;
        b = a;
        a = s;
    }
    if(c%a==0)return "YES";
    return "NO";
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        string result = solve(a, b, c);
        cout << result << "\n";
    }
    return 0;
}
