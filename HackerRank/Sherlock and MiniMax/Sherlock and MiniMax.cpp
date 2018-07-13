#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int n,l1,l2;
vector<long long int> numbers;
long long low,high;
int main() {

    cin>>n;

    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        numbers.push_back(x);
    }

    cin>>low>>high;

    sort(numbers.begin(),numbers.end());
    l1 = upper_bound(numbers.begin(),numbers.end(),low)-numbers.begin();
    if(l1!=0)
        l1--;

    l2 = upper_bound(numbers.begin(),numbers.end(),high)-numbers.begin();

    if(numbers[l2-1]==high)
        l2--;

    if(l2 == n)
        l2--;

    long long res = low;
    long long mDist = abs(numbers[l1]-low);
    if(l1+1<n-1){
        mDist = min(mDist, abs(numbers[l1+1]-low));
    }

    for(int i=l1+1;i<=l2;i++){
        long long temp = floor((numbers[i]+numbers[i-1])/2.0);
        long long dist = temp - numbers[i-1];
        if(dist>mDist && temp>=low && temp<=high){
            mDist = dist;
            res = temp;
        }
    }

    long long dist = abs(numbers[l2]-high);
    if(l2-1 >=0){
        dist = min(dist,abs(numbers[l2-1]-high));
    }


    if(dist>mDist) {
        mDist = dist;
        res = high;
    }

    //cout<<res<<' '<<mDist<<'\n';
    cout<< res<< '\n';
    return 0;
}

