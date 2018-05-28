#include <iostream>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int heapMin[100001];
int heapMax[100001];
int maxHeapSize = 0;
int minHeapSize = 0;

int getRightChildIndex(int index){return index*2+2;}
int getLeftChildIndex(int index){return index*2+1;}
int getParentIndex(int childIndex){return (childIndex-1)/2;}

int hasMaxRightChild(int index){return getRightChildIndex(index) < maxHeapSize;}
int hasMaxLeftChild(int index){return getLeftChildIndex(index) < maxHeapSize;}
int hasMinRightChild(int index){return getRightChildIndex(index) < minHeapSize;}
int hasMinLeftChild(int index){return getLeftChildIndex(index) < minHeapSize;}
int hasParent(int index){return getParentIndex(index)>=0 && index != 0;}

int getMaxLeftChild(int index){return heapMax[getLeftChildIndex(index)];}
int getMaxRightChild(int index){return heapMax[getRightChildIndex(index)];}
int getMaxParent(int childIndex){return heapMax[getParentIndex(childIndex)];}

int getMinLeftChild(int index){return heapMin[getLeftChildIndex(index)];}
int getMinRightChild(int index){return heapMin[getRightChildIndex(index)];}
int getMinParent(int childIndex){return heapMin[getParentIndex(childIndex)];}
int getMaxRoot(){return heapMax[0];}
int getMinRoot(){return heapMin[0];}

bool getHeap(int num){
    if (maxHeapSize == 0)
        return true;
    if(getMaxRoot()<num)
        return false;
    else
        return true;
}

void minHeapifyUp(){
    int index = minHeapSize-1;
    while (hasParent(index) && getMinParent(index)>heapMin[index]) {
        swap(heapMin[getParentIndex(index)], heapMin[index]);
        index = getParentIndex(index);
    }
}

void maxHeapifyUp(){
    int index = maxHeapSize-1;
    while (hasParent(index) && getMaxParent(index)<heapMax[index]) {
        swap(heapMax[getParentIndex(index)], heapMax[index]);
        index = getParentIndex(index);
    }
}

void maxHeapifyDown(){
    int index = 0;
    //printf("Has Left child %d",hasMaxLeftChild(index));
    while(hasMaxLeftChild(index)){
        int largerChildIndex = getLeftChildIndex(index);
        if(hasMaxRightChild(index) && getMaxRightChild(index) > getMaxLeftChild(index))
            largerChildIndex = getRightChildIndex(index);
        if (heapMax[index]>heapMax[largerChildIndex]) {
            break;
        }
        swap(heapMax[index], heapMax[largerChildIndex]);
        index = largerChildIndex;
    }
}

void minHeapifyDown(){
    int index = 0;
    while(hasMinLeftChild(index)){
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasMinRightChild(index) && getMinRightChild(index) < getMinLeftChild(index))
            smallerChildIndex = getRightChildIndex(index);
        if (heapMin[index]<heapMin[smallerChildIndex]) {
            break;
        }
        swap(heapMin[index], heapMin[smallerChildIndex]);
        index = smallerChildIndex;
    }
}

int popMaxHeap(){
    int root = getMaxRoot();
    heapMax[0]=heapMax[maxHeapSize-1];
    maxHeapSize--;
    maxHeapifyDown();
    return root;
}

void pushMinHeap(int num){
    heapMin[minHeapSize] = num;
    minHeapSize++;
    minHeapifyUp();
}

int popMinHeap(){
    int root = getMinRoot();
    heapMin[0]=heapMin[minHeapSize-1];
    minHeapSize--;
    minHeapifyDown();
    return root;
}

void pushMaxHeap(int num){
    heapMax[maxHeapSize] = num;
    maxHeapSize++;
    maxHeapifyUp();
}

int main(){
    int numCount;
    cin>>numCount;
    while(numCount--){
        int num;
        cin>>num;

        if(getHeap(num)){
            pushMaxHeap(num);
            if(maxHeapSize>minHeapSize+1){
                int max = popMaxHeap();
                pushMinHeap(max);
            }
        }else{
            pushMinHeap(num);
            if(minHeapSize>maxHeapSize+1){
                int min = popMinHeap();
                pushMaxHeap(min);
            }
        }

        if(minHeapSize==maxHeapSize){
            double res = 1.0*(getMaxRoot()+getMinRoot())/2.0;
            printf("%.1f\n",res);
        }else if(minHeapSize>maxHeapSize){
            printf("%.1f\n",1.0*getMinRoot());
        }else{
            printf("%.1f\n",1.0*getMaxRoot());
        }
    }
 return 0;
}
