#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int t,n,c,m,wrapper,chocolate,temp_choco;
    cin >> t;

    while(t--){

        cin >> n >> c >> m;
        wrapper=n/c;
        chocolate=n/c;

        while(wrapper>=m)
        {
            temp_choco=wrapper/m;
            wrapper=wrapper%m;
            wrapper=wrapper+temp_choco;
            chocolate+=temp_choco;
        }
        printf("%d\n",chocolate);

    }
    return 0;
}

