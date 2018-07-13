#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct node{
    long long start=0,close=0;
}number[10000001];

int main() {

    int n, q, x, y, val;
    long long res=0, sum;

    cin>>n>>q;

    for(int i=0;i<q;i++){
        cin>>x>>y>>val;
        number[x-1].start+=val;
        number[y-1].close+=val;
    }

    for(int i=0;i<n;i++){
        sum+=number[i].start;
        res = max(res,sum);
        sum-=number[i].close;
    }
    cout<<res;
    return 0;
}

