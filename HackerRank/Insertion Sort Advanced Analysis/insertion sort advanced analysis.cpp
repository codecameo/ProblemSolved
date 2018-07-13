#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int number[100001], numberSort[100001];
int shift=0,n;

void mergeSort(int low, int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(low,mid);
    mergeSort(mid+1,high);

    int l0=low,l1=mid+1,index=low;

    while(l0<=mid || l1<=high) {
        if(l0>mid){
            number[index] = numberSort[l1];
            l1++;
            index++;
            continue;
        }

        if(l1>high){
            number[index] = numberSort[l0];
            l0++;
            index++;
            continue;
        }

        if(numberSort[l1]<numberSort[l0]){
            shift += l1-index;
            number[index] = numberSort[l1];
            l1++;
        }else{
            number[index]=numberSort[l0];
            l0++;
        }
        index++;
    }
    for(int i=low;i<=high;i++)numberSort[i]=number[i];
}


int main() {

    int tKase;
    cin>>tKase;
    while(tKase--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>number[i];
            numberSort[i] = number[i];
        }
        mergeSort(0,n-1);
        printf("%d\n",shift);
    }
    return 0;
}
