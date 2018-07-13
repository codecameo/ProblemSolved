#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int height[100001],building;
    cin>>building;
    for(int i=0;i<building;i++){
        cin >> height[i];
    }

    int botEnergy=0;

    for(int i=building-1;i>=0;i--){
        botEnergy = ceil((botEnergy+height[i])/2.0);
    }

     cout<<botEnergy<<'\n';
     return 0;
}

