#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<algorithm>
#include<iostream>

using namespace std;

int numbers[101], N, K;

int partitionIndex(int lo, int hi){
    int pivot = numbers[hi];
    int i = lo-1;

    for(int j=lo;j<=hi;j++){
        if(numbers[j]>pivot){
            i++;
            swap(numbers[j], numbers[i]);
        }
    }
    swap(numbers[i+1],numbers[hi]);
    return i+1;
}

void quickSort(int lo, int hi){
    if(lo>=hi) return;
    int pivot = partitionIndex(lo,hi);
    quickSort(lo, pivot - 1);
    quickSort(pivot + 1, hi);
}

int main(void){

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> numbers[i];
    }

    quickSort(0,N-1);
    int result = 0;
    for(int i=0;i<N;i++){
        result += (i/K+1)*numbers[i];
    }

    cout << result << "\n";

   return 0;
}

