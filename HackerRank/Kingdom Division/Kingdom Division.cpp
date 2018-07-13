#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int res;
bool table[100001];

struct Edges{
int x,y;
}edges[100001];

/*bool check(){

    bool found;

    for(int i = 1; i <= n; i++) {
        bool flag = table[i];
        found = false;
        for(int j = 0; j < edges[i].size(); j++) {
            if(flag == table[edges[i][j]]){
                found = true;
                break;
            }
        }

        //printf("\nFound %d\n",found);

        if(!found){
            return found;
        }
    }
    return found;
}*/

bool check(){

    //bool safe[100001];

    set<int> safe;

    for(int i=0; i< n-1; i++){

        //printf("Edge %d -> %d and %d -> %d\n",edges[i].x,table[edges[i].x],edges[i].y,table[edges[i].y]);

        if(table[edges[i].x] == table[edges[i].y]){
            safe.insert(edges[i].x);
            safe.insert(edges[i].y);
        }
    }
    if(safe.size() == n)
        return true;
    return false;
}



void backtrack(int index){

    //printf("%d\n",index);

    if(index == n+1){
        //printf("\n");
        if(check()){
            res=res+1;
            res = res % 1000000007;
            //printf("RES %d\n"+res);

            for(int i=1; i<=n; i++){
                printf("(%d %d) ",i,table[i]);
            }
            printf("\n");
        }

        return;
    }

    table[index] = false;
    backtrack(index+1);

    if(index!=1){
        table[index] = true;
        backtrack(index+1);
    }
}

int main(){
    cin >> n;

    res = 0;

    for(int a0 = 0; a0 < n-1; a0++){
        int u;
        int v;
        cin >> u >> v;
        edges[a0].x = u;
        edges[a0].y = v;
    }

    backtrack(1);

    printf("%d\n",res);

    return 0;
}

