#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int forest[11][11];
bool flag[11][11];
struct co_ordinate{
    int x,y;
};

void clearFlag(){
    for(int i=0; i<=n;i++)
        for(int j=0; j<=m;j++)
            flag[i][j]=false;
}

bool isValid(co_ordinate pos){
    return pos.x>=0 && pos.x <n && pos.y >=0 && pos.y<m;
}

bool isReachAble(co_ordinate pos){
    return isValid(pos) && forest[pos.x][pos.y] == 1 && !flag[pos.x][pos.y];
}

int dfs(co_ordinate curPosition){

    //printf("%d %d\n",curPosition.x,curPosition.y);
    co_ordinate up, down, left, right, top_left, top_right, bottom_left, bottom_right;
    int validStep = 1;

    up.x = curPosition.x-1;
    up.y = curPosition.y;

    down.x = curPosition.x+1;
    down.y = curPosition.y;

    left.x = curPosition.x;
    left.y = curPosition.y-1;

    right.x = curPosition.x;
    right.y = curPosition.y+1;

    top_left.x = curPosition.x - 1;
    top_left.y = curPosition.y - 1;

    top_right.x = curPosition.x - 1;
    top_right.y = curPosition.y + 1;

    bottom_left.x = curPosition.x + 1;
    bottom_left.y = curPosition.y - 1;

    bottom_right.x = curPosition.x + 1;
    bottom_right.y = curPosition.y + 1;



    if(isReachAble(up)){
        flag[up.x][up.y] = true;
        validStep+=dfs(up);
    }
    if(isReachAble(down)){
        flag[down.x][down.y] = true;
        validStep+=dfs(down);
    }
    if(isReachAble(left)){
        flag[left.x][left.y] = true;
        validStep+=dfs(left);
    }
    if(isReachAble(right)){
        flag[right.x][right.y] = true;
        validStep+=dfs(right);
    }

    if(isReachAble(top_left)){
        flag[top_left.x][top_left.y] = true;
        validStep+=dfs(top_left);
    }

    if(isReachAble(top_right)){
        flag[top_right.x][top_right.y] = true;
        validStep+=dfs(top_right);
    }

    if(isReachAble(bottom_left)){
        flag[bottom_left.x][bottom_left.y] = true;
        validStep+=dfs(bottom_left);
    }

    if(isReachAble(bottom_right)){
        flag[bottom_right.x][bottom_right.y] = true;
        validStep+=dfs(bottom_right);
    }

    return validStep;
}

int main() {
    cin >> n >> m;
    int sum = 0;
    clearFlag();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>forest[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!flag[i][j] && forest[i][j]==1){
                co_ordinate src;
                src.x = i;
                src.y = j;
                if(isReachAble(src)){
                    flag[i][j] = true;
                    int temp = dfs(src);
                    sum = max(sum,temp);
                    printf("Temp %d Region %d\n",temp,sum);
                }
            }
        }
    }

    printf("%d\n",sum);

    return 0;
}


