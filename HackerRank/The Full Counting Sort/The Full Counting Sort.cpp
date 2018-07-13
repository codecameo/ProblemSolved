#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct word{
    int value;
    string s;
}numbers[1000001];

struct indexing{
    int value;
    int index;
}helper[1000001], helperSort[1000001];

int n;

void countingSort(){
    int arr[101] = {0};
    vector<indexing> indexs[1000001];

    for(int i=0;i<n;i++){
        arr[helper[i].value]++;
        indexs[helper[i].value].push_back(helper[i]);
    }

    for(int i=1;i<=100;i++){
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<n;i++){
        int index = helper[i].value;
        int lastItem = indexs[index].size()-1;
        helperSort[arr[index]-1] = indexs[index][lastItem];
        arr[index]--;
        indexs[index].pop_back();
    }
}

int main() {

    cin>>n;

    for(int i=0;i<n;i++){
        cin>> numbers[i].value;
        getchar();
        cin>>numbers[i].s;
        helper[i].value = numbers[i].value;
        helper[i].index = i;
    }

    countingSort();

    for(int i=0;i<n;i++){
        if(helperSort[i].index<n/2)
            cout<<"- ";
        else
            cout<<numbers[helperSort[i].index].s<<' ';
    }

    return 0;
}
