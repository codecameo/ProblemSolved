#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
string forest[101];
bool flag[101][101];
struct co_ordinate{
    int x,y;
}src;

void clearFlag(){
    for(int i=0; i<=n;i++)
        for(int j=0; j<=m;j++)
            flag[i][j]=false;
}

bool isValid(co_ordinate pos){
    return pos.x>=0 && pos.x <n && pos.y >=0 && pos.y<m;
}

bool isReachAble(co_ordinate pos){
    return isValid(pos) && forest[pos.x][pos.y] != 'X' && !flag[pos.x][pos.y];
}

int dfs(co_ordinate curPosition, int waves){
    //printf("%d %d\n",curPosition.x,curPosition.y);
    if(forest[curPosition.x][curPosition.y] == '*') return waves;

    co_ordinate up, down, left, right;
    int validStep=0;

    up.x = curPosition.x-1;
    up.y = curPosition.y;

    down.x = curPosition.x+1;
    down.y = curPosition.y;

    left.x = curPosition.x;
    left.y = curPosition.y - 1;

    right.x = curPosition.x;
    right.y = curPosition.y + 1;

    if(isReachAble(up))
        validStep++;
    if(isReachAble(down))
        validStep++;
    if(isReachAble(left))
        validStep++;
    if(isReachAble(right))
        validStep++;

    if(validStep == 0) return -1;

    if(isReachAble(up)){
        int w = waves;
        if(validStep>=2) w++;
        flag[up.x][up.y] = true;
        int res = dfs(up,w);
        if(res != -1) return res;
    }

    if(isReachAble(down)){
        int w = waves;
        if(validStep>=2) w++;
        flag[down.x][down.y] = true;
        int res = dfs(down,w);
        if(res != -1) return res;
    }

    if(isReachAble(left)){
        int w = waves;
        if(validStep>=2) w++;
        flag[left.x][left.y] = true;
        int res = dfs(left,w);
        if(res != -1) return res;
    }

    if(isReachAble(right)){
        int w = waves;
        if(validStep>=2) w++;
        flag[right.x][right.y] = true;
        int res = dfs(right,w);
        if(res != -1) return res;
    }
    return -1;
}

int main() {

    int tKase,k;
    scanf("%d",&tKase);
    while(tKase--){
        clearFlag();
        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin>>forest[i];
        }
        cin>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(forest[i][j]=='M'){
                    src.x = i;
                    src.y = j;
                    break;
                }
            }
        }
        flag[src.x][src.y] = true;
        int res = dfs(src,0);

        if(res==k)
            cout<<"Impressed\n";
        else
            cout<<"Oops!\n";
    }

    return 0;
}

