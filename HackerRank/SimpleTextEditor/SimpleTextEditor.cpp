#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
    string str, optStr;
    stack <string> stk;

    int tKase, opt, index, strLen;
    cin >> tKase;
    str = "";

    while(tKase--){
            //printf("Enter op : ");
        cin>>opt;
        switch(opt){
            case 1:
                //printf("Enter String: \n");
                cin>>optStr;
                stk.push(str);
                str.append(optStr);
            break;

            case 2:
                //printf("Enter String To Erase: \n");
                cin>>index;
                stk.push(str);
                strLen = str.length() - index;
                str.erase(strLen, index);
            break;
            case 3:
                //printf("Printing String: \n");
                cin >> index;
                cout<<str.at(index-1)<<endl;
            break;
            case 4:
                //printf("Revert String: \n");
                str = stk.top();
                stk.pop();
            break;
        }
    }
    return 0;
}
