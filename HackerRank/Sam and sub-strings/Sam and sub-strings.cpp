#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int getNumberOfDigits (int i){
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int getBase(int digit){
    if(digit==1)return 1;
    else if(digit==2)return 10;
    else if(digit==3)return 100;
    else if(digit==4)return 1000;
    else if(digit==5)return 10000;
    return 100000;
}

int main() {

    int number;
    cin>>number;
    int digit = getNumberOfDigits(number);
    int base = getBase(digit);
    //printf("Base %d\n",base);
    long long res=0;
    for(int i=base; i!=0; i=i/10){
        //printf("i -> %d\n",i);
        for(int j=i; j!=0; j=j/10){
            //printf("j -> %d\n",j);
            int x = number/j;
            //printf("%d\n",x);
            res+=x;
            res = res%1000000007;
        }
        number=number%i;
    }
    cout<<res<<'\n';
    return 0;
}

