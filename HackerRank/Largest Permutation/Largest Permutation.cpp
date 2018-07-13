#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k,num[100001],position[100001];

    cin>>n>>k;

    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
        position[num[i]]=i;
    }

    for(int i=0;i<n && k>0;i++,k--){
        int nm = n-i;
        int index = position[nm];
        if(index==i){
            k++;
            continue;
        }
        int temp = num[i];
        num[i]=nm;
        num[index]=temp;
        position[nm] = i;
        position[temp] = index;

    }

    for(int i=0;i<n;i++){
        printf("%d ",num[i]);
    }

    return 0;
}

