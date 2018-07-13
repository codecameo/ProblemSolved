#include <bits/stdc++.h>

using namespace std;

int number[1024]={0};

void buildString(){
    int len = 1;
    int high = 1;
    while(len<1024){
        for(int i=0;i<len;i++){
        number[i+len]= 1-number[i];
        }
        len = len*2;
        high = high*2;
    }

}

int duplication(int x){
    return number[x];
}

int main() {

    buildString();

    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int x;
        cin >> x;
        int result = duplication(x);
        cout << result << endl;
    }
    return 0;
}
