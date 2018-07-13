#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int n, choco[10001];

long long int getMinStep(long long int choco){

    long long int res;
    res = choco/5;
    choco = choco%5;
    res= res + (choco/2) + (choco%2);
    return res;
}

int main() {

    int tKase;
    scanf("%d",&tKase);
    while(tKase--){
        int minChoco = 1001;
        scanf("%d",&n);
        for(int i = 0; i < n; i++){
            scanf("%d",&choco[i]);
            if(minChoco>choco[i])
                minChoco = choco[i];
        }

        long long int steps = 0, minSteps;

        for(int j =0;j<6;j++){
            steps=0;
            for(int i=0;i<n;i++) {
                steps+= getMinStep(abs(choco[i]-(minChoco-j)));
            }
            if(j==0)
                minSteps = steps;
            else
                minSteps = min(minSteps,steps);
        }

        printf("%lld\n",minSteps);

    }


    return 0;
}

