
#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer{
    long long int arrival, pizza;
};

vector<Customer> customer;
Customer heapMin[100001];
int minHeapSize = 0;

int getRightChildIndex(int index){return index*2+2;}
int getLeftChildIndex(int index){return index*2+1;}
int getParentIndex(int childIndex){return (childIndex-1)/2;}

int hasMinRightChild(int index){return getRightChildIndex(index) < minHeapSize;}
int hasMinLeftChild(int index){return getLeftChildIndex(index) < minHeapSize;}
int hasParent(int index){return getParentIndex(index)>=0 && index != 0;}

Customer getMinLeftChild(int index){return heapMin[getLeftChildIndex(index)];}
Customer getMinRightChild(int index){return heapMin[getRightChildIndex(index)];}
Customer getMinParent(int childIndex){return heapMin[getParentIndex(childIndex)];}

Customer getMinRoot(){return heapMin[0];}

bool comp(Customer &c1, Customer &c2){
    if (c1.arrival == c2.arrival) {
        return c1.pizza < c2.pizza;
    }else{
        return c1.arrival < c2.arrival;
    }
}

void minHeapifyUp(){
    int index = minHeapSize-1;
    while (hasParent(index) && getMinParent(index).pizza>heapMin[index].pizza) {
        swap(heapMin[getParentIndex(index)], heapMin[index]);
        index = getParentIndex(index);
    }
}

void minHeapifyDown(){
    int index = 0;
    while(hasMinLeftChild(index)){
        int smallerChildIndex = getLeftChildIndex(index);
        if(hasMinRightChild(index) && getMinRightChild(index).pizza < getMinLeftChild(index).pizza)
            smallerChildIndex = getRightChildIndex(index);
        if (heapMin[index].pizza<heapMin[smallerChildIndex].pizza) {
            break;
        }
        swap(heapMin[index], heapMin[smallerChildIndex]);
        index = smallerChildIndex;
    }
}

void pushMinHeap(Customer cus){
    heapMin[minHeapSize] = cus;
    minHeapSize++;
    minHeapifyUp();
}

Customer popMinHeap(){
    Customer root = getMinRoot();
    heapMin[0]=heapMin[minHeapSize-1];
    minHeapSize--;
    minHeapifyDown();
    return root;
}

int main(){
    int n;
    long long int timeLine = 0, waitingTime = 0;
    cin>>n;
    int index = 0;
    for(int i=0; i<n; i++){
        Customer c;
        cin >> c.arrival>>c.pizza;
        customer.push_back(c);
    }
    sort(customer.begin(), customer.end(), comp);
    for(; index<n; index++){
        if(index == 0) {
            timeLine = customer[index].arrival;
        }
        if (customer[index].arrival > timeLine) break;
        pushMinHeap(customer[index]);
    }
    while (minHeapSize >0) {
        Customer c = popMinHeap();
        waitingTime += (timeLine - c.arrival) + c.pizza;
        timeLine += c.pizza;
        for(; index<n; index++){
            if (customer[index].arrival <= timeLine){
                pushMinHeap(customer[index]);
                continue;
            }else{
                if (minHeapSize >0) {
                    break;
                }else{
                    timeLine = customer[index].arrival;
                    pushMinHeap(customer[index]);
                }
            }
        }
    }
    long long int res = waitingTime/n;
    cout<<res<<endl;
    return 0;
}

