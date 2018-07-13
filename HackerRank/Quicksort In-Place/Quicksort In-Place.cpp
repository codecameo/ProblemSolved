#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<algorithm>

using namespace std;

int numbers[5001],n;


void print(){
    for(int i=0;i<n;i++){
        printf("%d ",numbers[i]);
    }
    printf("\n");
}

int partitionIndex(int lo, int hi){
    int pivot = numbers[hi];
    int i = lo-1;

    for(int j=lo;j<=hi;j++){
        if(numbers[j]<pivot){
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
    print();
    quickSort(lo, pivot - 1);
    quickSort(pivot + 1, hi);
}



int main() {
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&numbers[i]);
    }

    quickSort(0,n-1);

    return 0;
}
