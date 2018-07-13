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

int board[26][26], n;
struct co_ordinate{
int x,y,breadth;
};

void clearBoard(){
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            board[i][j]=-1;
}

bool isValid(co_ordinate pos){
    return pos.x>=0 && pos.x<n && pos.y>=0 && pos.y<n;
}

bool isExplored(co_ordinate pos){
    return board[pos.x][pos.y] != -1;
}

bool isFound(co_ordinate pos){
 return pos.x == n-1 && pos.y == n-1;
}

bool savePosition(co_ordinate pos, int cnt, queue<co_ordinate> &q){
    if(isValid(pos) && !isExplored(pos)){
            board[pos.x][pos.y] = cnt;
            if(isFound(pos)){
                return true;
            }
            q.push(pos);
    }
    return false;
}

void bfs(int a, int b){
    queue<co_ordinate> q;
    co_ordinate position, pos1,pos2,pos3,pos4,pos5,pos6,pos7,pos8;
    position.x=0;
    position.y=0;
    position.breadth=0;
    q.push(position);
    board[position.x][position.y]=0;

    while(!q.empty()){
        position = q.front(); q.pop();
        int cnt = position.breadth;
        //printf("%d %d %d\n",position.x,position.y, cnt);

        pos1.x = position.x - a;    pos1.y = position.y - b;    pos1.breadth = cnt + 1;
        pos2.x = position.x - a;    pos2.y = position.y + b;    pos2.breadth = cnt + 1;
        pos3.x = position.x + a;    pos3.y = position.y - b;    pos3.breadth = cnt + 1;
        pos4.x = position.x + a;    pos4.y = position.y + b;    pos4.breadth = cnt + 1;
        pos5.x = position.x - b;    pos5.y = position.y - a;    pos5.breadth = cnt + 1;
        pos6.x = position.x - b;    pos6.y = position.y + a;    pos6.breadth = cnt + 1;
        pos7.x = position.x + b;    pos7.y = position.y - a;    pos7.breadth = cnt + 1;
        pos8.x = position.x + b;    pos8.y = position.y + a;    pos8.breadth = cnt + 1;

        if(savePosition(pos1, cnt+1, q))
            return;
        if(savePosition(pos2, cnt+1, q))
            return;
        if(savePosition(pos3, cnt+1, q))
            return;
        if(savePosition(pos4, cnt+1, q))
            return;
        if(savePosition(pos5, cnt+1, q))
            return;
        if(savePosition(pos6, cnt+1, q))
            return;
        if(savePosition(pos7, cnt+1, q))
            return;
        if(savePosition(pos8, cnt+1, q))
            return;




    }
}

int main(){
    cin >> n;

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            clearBoard();
            bfs(i,j);
            printf("%d ",board[n-1][n-1]);
        }
        printf("\n");
    }



    return 0;
}

