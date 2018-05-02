#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
 int value, left, right;
}node[1025];

void printIn(Node nd, int depth,int k){

    int left, right;

    if(depth>=k && depth%k==0){
        swap(node[nd.value].left, node[nd.value].right);
        nd = node[nd.value];
        //left = nd.right;
        //right = nd.left;
    }


    if(nd.left != -1)
        printIn(node[nd.left], depth+1, k);
    cout<<nd.value<<' ';
    if(nd.right != -1)
        printIn(node[nd.right], depth+1, k);

}

int main() {

    int n;

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>node[i].left>>node[i].right;
        node[i].value = i;
    }

    int tkase;
    cin>> tkase;
    for(int i=0;i<tkase; i++){
        int k;
        cin >> k;
        printIn(node[1], 1, k);
        cout<<endl;
    }

    return 0;
}

