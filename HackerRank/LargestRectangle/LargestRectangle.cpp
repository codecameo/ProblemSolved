#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stab.h>
#include <string>
#include <stack>
using namespace std;

int table[1000001];

long largestRectangle(vector <int> h) {
    stack<int> stk;
    long ans = -1;

    for(int i = 0; i < h.size(); i++) {
            //printf("Num %d\n",h[i]);
        if(stk.empty()){
            //printf("Empty\n");
            stk.push(h[i]);
            table[h[i]] = i;
            continue;
        }

        if(stk.top() > h[i]){
                //printf("Top %d\n",stk.top());
            int indx = i;
            while(!stk.empty()){
                int num = stk.top();
                //printf("Popped %d Size %ld\n",num,stk.size());
                if(num == h[i]) break;
                else if(num < h[i]){
                    stk.push(h[i]);
                    table[h[i]] = indx;
                    //printf("%d %d\n",h[i],indx);
                    break;
                }else{
                    int index = table[num];
                    long temp = (i-index)*num;
                    ans = max(ans, temp);
                    indx = index;
                    stk.pop();
                    //printf("## %d %d %ld\n",num,index,ans);
                }
            }
            if(stk.empty()){
                stk.push(h[i]);
                table[h[i]] = indx;
                //printf("Insert %d index %d\n",h[i],indx);
            }
        }else{
            //printf("## %d %d\n",h[i], i);
            stk.push(h[i]);
            table[h[i]] = i;
        }
    }

    int i = h.size();
    while(!stk.empty()){
            int num = stk.top();
            stk.pop();
            int index = table[num];
            //printf("Index %d Num %d\n",index,num);
            long temp = (i-index)*num;
            ans = max(ans, temp);
        }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int h_i = 0; h_i < n; h_i++){
       cin >> h[h_i];
    }
    long result = largestRectangle(h);
    cout << result << endl;
    return 0;
}

