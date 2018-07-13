#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int performance[100001];

struct Candy{
    int candy;
    int offset;
}candies[100001];

int main() {

    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>> performance[i];
    candies[0].candy=1;
    candies[0].offset=0;

    for(int i=1;i<n;i++){
        if(performance[i-1]>performance[i]){
            candies[i].candy=1;
            candies[i].offset=1;
        }else if(performance[i-1]<performance[i]){
            candies[i].candy=candies[i-1].candy+1;
            candies[i].offset=0;
        }else{
            candies[i].candy=1;
            candies[i].offset=0;
        }
    }

    //for(int i=0;i<n;i++)printf("(%d %d)\n",candies[i].candy,candies[i].offset);

    int res=0;
    for(int i= n-1;i>=0;i--){
        int cnt = candies[i].candy + candies[i].offset;
        //printf("%d Candy %d\n",i,candies[i].candy);
        res+=candies[i].candy;
        if(i>0 && candies[i].offset>0)
            if(candies[i-1].candy<cnt)
                candies[i-1].candy=cnt;
    }

    cout<<res<<endl;
    return 0;
}

