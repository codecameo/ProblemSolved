#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int convertToDec(int base, int num){
    if (base == 10)
        return num;
    else if(base <= 1)
        return 0;
    int dec_value = 0;
    int mult = 1;
    int temp = num;
    while (temp){
        int last_digit = temp % 10;
        temp = temp/10;
        if (last_digit>=base) {
            return 0;
        }
        dec_value += last_digit * mult;
        mult = mult*base;
    }
    return dec_value;
}

int main(){
    int t;
    cin>>t;
    map<int, int> dateMap;
    while(t--){
        int m,d;
        cin>>m>>d;
        d = convertToDec(m, d);
        dateMap[d]++;
        
    }
    long long int res = 0;
    for(int i=1;i<=37;i++){
        int n = dateMap[i];
        res+= ((long long int)(n)*(n-1))/2;
    }
    cout<<res<<endl;
    return 0;
}


