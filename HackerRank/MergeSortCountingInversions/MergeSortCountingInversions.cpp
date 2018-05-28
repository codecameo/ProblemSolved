#include <iostream>
#include <stack>
#include <math.h>
#include <stdio.h>

using namespace std;

int num[100001];

long merge(int start, int end){
    if (start == end) return 0;
    int mid = (start+end)/2;
    long swap;
    swap = merge(start, mid);
    swap+=merge(mid+1, end);
    int diff = end-start;
    int temp[diff+1];
    int pointer1 = start, pointer2 = mid+1;

    for(int i=0;i<diff+1;i++){
        if(pointer1>mid){
            temp[i] = num[pointer2];
            pointer2++;
            continue;
        }else if(pointer2>end){
            temp[i] = num[pointer1];
            pointer1++;
            continue;
        }
        if(num[pointer1]>num[pointer2]){
            temp[i] = num[pointer2];
            pointer2++;
            swap += mid-pointer1+1;
        }else {
            temp[i] = num[pointer1];
            pointer1++;
        }
    }

    for (int i=0; i<diff+1; i++) {
        num[start+i]=temp[i];
    }
    return swap;
}

int main(){
    int tKase;
    cin >> tKase;
    while(tKase--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>num[i];
        cout<<merge(0 , n-1)<<endl;
    }
    return 0;
}
