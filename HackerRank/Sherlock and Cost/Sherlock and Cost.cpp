#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int b[100001],n;
int table[100001][2];

void dp(int index){
    //printf("%d %d\n",prev,cur);
    if(index==0){
        table[index][0] = 0;
        table[index][1] = 0;
        return;
    }

    dp(index-1);
    int diff1 = abs(b[index-1] - b[index]);
    int diff2 = abs(b[index]-1);

    table[index][0] = max(table[index-1][1]+abs(b[index-1]-1) , table[index-1][0]);
    table[index][1] = max(table[index-1][1]+diff1, table[index-1][0]+diff2);

}

int main() {

    int tKase, res;
    cin>>tKase;
    while(tKase--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>b[i];
        dp(n-1);
        res = max(table[n-1][0],table[n-1][1]);
        cout<<res<<endl;
    }

    return 0;
}

