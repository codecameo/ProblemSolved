#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    vector<int> width(n);
    for(int width_i = 0;width_i < n;width_i++){
       cin >> width[width_i];
    }
    for(int a0 = 0; a0 < t; a0++){
        int x,y,v=4;
        cin >> x >> y;

        for(int i=x;i<=y;i++)
        {
            v=min(v,width[i]);
        }
        printf("%d\n",v);

    }
    return 0;
}
