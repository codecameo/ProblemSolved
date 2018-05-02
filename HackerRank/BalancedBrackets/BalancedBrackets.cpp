#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stab.h>
#include <string>
#include <stack>
using namespace std;

string isBalanced(string s) {

    stack<char> st;
    int len = s.length();
    for(int i=0;i<len;i++){
        char brac = s.at(i);
        printf("%c %d\n",brac, brac);
        if(brac == ')' || brac == '}' || brac == ']'){
            if(st.empty())
                return "NO";
            char b = st.top();
            st.pop();

            if((b == '(' && brac == ')') || (b == '{' && brac == '}') || (b == '[' && brac == ']')){

            }else{
                return "NO";
            }



        }else{
            st.push(brac);
        }
    }

   if(st.empty())
        return "YES";
    else
        return "NO";
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    return 0;
}

