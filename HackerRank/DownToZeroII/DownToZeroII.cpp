#include <iostream>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

/*
 * Complete the downToZero function below.
 */

vector<int> divisor[1000001];
int steps[1000001] = {0};

void getPrimes(){
    divisor[0].push_back(0);
    divisor[1].push_back(1);
    for(int i=2;i<=1000000;i++){
        for(int j=i; j<=1000000; j+=i){
            divisor[j].push_back(i);
        }
    }
}

void getSteps(){
    steps[0] = 0;
    steps[1] = 1;
    steps[2] = 2;
    steps[3] = 3;

    for(int i=4;i<1000001;i++){
        int x = 1000001;
        for(int j=0;j<divisor[i].size()-1;j++){
            if((long int)divisor[i][j]*divisor[i][j]>(long int)i) break;
            int y = steps[i/divisor[i][j]];
            x = min(x, y);
        }
        x = min(x, steps[i-1]);
        steps[i]=x+1;
    }

}

int main(){
    getPrimes();
    getSteps();
    int q;
    cin >> q;

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        int result = steps[n];
        cout << result << "\n";
    }

    return 0;
}

