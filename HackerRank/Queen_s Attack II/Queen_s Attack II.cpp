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

const int TOP = 0;
const int BOTTOM = 1;
const int LEFT = 2;
const int RIGHT = 3;
const int TOP_LEFT = 4;
const int TOP_RIGHT = 5;
const int BOTTOM_LEFT = 6;
const int BOTTOM_RIGHT = 7;
const int NONE = 8;

int rQueen;
int cQueen;

struct Obs{
int x,y,distance;
}obstacle[8];

/**
0 - > Top
1 - > Bottom
2 -> Left
3 -> Right
4 -> Top-Left
5 -> Top-Right
6 -> Bottom-Left
7 -> Bottom-Right
*/

int direction(int x, int y){

    if(y == cQueen){
        if(x < rQueen)
            return LEFT;
        else
            return RIGHT;
    }
    else if(x == rQueen){
        if(y < cQueen)
            return BOTTOM;
        else
            return TOP;
    }
    else if(abs(y-cQueen) == abs(x-rQueen)){
        if(x < rQueen){
            if(y<cQueen)
                return BOTTOM_LEFT;
            else
                return TOP_LEFT;
        }
        else{
            if(y<cQueen)
                return BOTTOM_RIGHT;
            else
                return TOP_RIGHT;
        }
    }
    else
        return NONE;

}

int disnatce(Obs obs, int direct){

    if(direct == LEFT || direct == RIGHT){
        return abs(obs.x-rQueen)-1;
    }else if(direct == TOP || direct == BOTTOM){
        return abs(obs.y-cQueen)-1;
    }
    else if(direct == TOP_RIGHT || direct == TOP_LEFT || direct == BOTTOM_RIGHT || direct == BOTTOM_LEFT){
        return abs(obs.y-cQueen)-1;
    }
    else
        return -1;
}

void updateObstacle(int x, int y){

    int direct = direction(x,y);
    if(direct == NONE) return;

    Obs obs;
    obs.x =  x;
    obs.y = y;

    int distance = disnatce(obs, direct);

    if(distance < obstacle[direct].distance){
        obstacle[direct].x = obs.x;
        obstacle[direct].y = obs.y;
        obstacle[direct].distance = distance;
    }
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    cin >> rQueen >> cQueen;

    obstacle[LEFT].x = 0;
    obstacle[LEFT].y = cQueen;
    obstacle[LEFT].distance = disnatce(obstacle[LEFT],LEFT);

    obstacle[RIGHT].x = n+1;
    obstacle[RIGHT].y = cQueen;
    obstacle[RIGHT].distance = disnatce(obstacle[RIGHT],RIGHT);

    obstacle[TOP].x = rQueen;
    obstacle[TOP].y = n+1;
    obstacle[TOP].distance = disnatce(obstacle[TOP],TOP);

    obstacle[BOTTOM].x = rQueen;
    obstacle[BOTTOM].y = 0;
    obstacle[BOTTOM].distance = disnatce(obstacle[BOTTOM], BOTTOM);

    int offset = min(abs(0-rQueen),abs(n+1-cQueen));

    obstacle[TOP_LEFT].x = rQueen - offset;
    obstacle[TOP_LEFT].y = cQueen + offset;
    obstacle[TOP_LEFT].distance = disnatce(obstacle[TOP_LEFT], TOP_LEFT);

    offset = min(abs(0-rQueen),abs(0-cQueen));

    obstacle[BOTTOM_LEFT].x = rQueen - offset;
    obstacle[BOTTOM_LEFT].y = cQueen - offset;
    obstacle[BOTTOM_LEFT].distance = disnatce(obstacle[BOTTOM_LEFT], BOTTOM_LEFT);

    offset = min(abs(n+1-rQueen),abs(n+1-cQueen));

    obstacle[TOP_RIGHT].x = rQueen + offset;
    obstacle[TOP_RIGHT].y = cQueen + offset;
    obstacle[TOP_RIGHT].distance = disnatce(obstacle[TOP_RIGHT], TOP_RIGHT);

    offset = min(abs(n+1-rQueen),abs(0-cQueen));

    obstacle[BOTTOM_RIGHT].x = rQueen + offset;
    obstacle[BOTTOM_RIGHT].y = cQueen - offset;
    obstacle[BOTTOM_RIGHT].distance = disnatce(obstacle[BOTTOM_RIGHT], BOTTOM_RIGHT);


    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;

        updateObstacle(rObstacle,cObstacle);
    }

    int count=0;

    for(int i = 0; i<8 ; i++){
        count+=obstacle[i].distance;
    }

    cout<< count << endl;

    return 0;
}
