#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int tKase, n;
    cin>>tKase;

    while(tKase--){

        int number[51];
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>number[i];
        }
        sort(number,number+n);

        int len = number[0], index = 0;
        double sum=0;
        for(int i=0;i<n;i++){
            if(number[i] != len){
                len = number[i];
                index = i;
            }
            sum+=(n+1)*1.0/(n-index+1)*1.0;
        }
        printf("%.2lf\n",sum);
    }
    return 0;
}
