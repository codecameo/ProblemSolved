#include <iostream>
#include <queue>
#include <stdio.h>
#include <map>
using namespace std;

int n;
struct point{
int x,y,level;
};

point start, goal;
queue<point> pointQueue;
bool visited[10001] = {false};

bool isValid(vector <string> grid, point p){
    return grid[p.x][p.y] == '.';
}

int index(point p){
    return p.x*n+p.y;
}

bool isGoal(point p){
    return goal.x == p.x && goal.y == p.y;
}

int up(vector <string> grid, point p){
    p.level++;
    p.y--;
    for(;p.y >=0; p.y--){
        if(!isValid(grid,p)) break;
        if(visited[index(p)]) continue;
        visited[index(p)] = true;
        if(isGoal(p)) return p.level;
        pointQueue.push(p);
    }
    return 0;
}


int down(vector <string> grid, point p){
    p.level++;
    p.y++;
    for(;p.y < n; p.y++){
        if(!isValid(grid,p)) break;
        if(visited[index(p)]) continue;
        visited[index(p)] = true;
        if(isGoal(p)) return p.level;
        pointQueue.push(p);
    }
    return 0;
}

int left(vector <string> grid, point p){
    p.level++;
    p.x--;
    for(;p.x >= 0; p.x--){
        if(!isValid(grid,p)) break;
        if(visited[index(p)]) continue;
        visited[index(p)] = true;
        if(isGoal(p)) return p.level;
        pointQueue.push(p);
    }
    return 0;
}


int right(vector <string> grid, point p){
    p.level++;
    p.x++;
    for(;p.x < n; p.x++){
        if(!isValid(grid,p)) break;
        if(visited[index(p)]) continue;
        visited[index(p)] = true;
        if(isGoal(p)) return p.level;
        pointQueue.push(p);
    }
    return 0;
}

int minimumMoves(vector <string> grid) {

    start.level = 0;
    pointQueue.push(start);
    visited[index(start)] = true;
    while(!pointQueue.empty()){
        point topPoint = pointQueue.front();
        pointQueue.pop();
        //if(visited[index(topPoint)]) continue;
        //visited[index(topPoint)] = true;
        if(up(grid, topPoint)) return topPoint.level+1;
        if(down(grid, topPoint)) return topPoint.level+1;
        if(left(grid, topPoint)) return topPoint.level+1;
        if(right(grid, topPoint)) return topPoint.level+1;
    }
    return 0;
}

int main() {
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0; grid_i < n; grid_i++){
       cin >> grid[grid_i];
    }
    cin >> start.x >> start.y >> goal.x >> goal.y;
    int result = minimumMoves(grid);
    cout<<result<<endl;
    return 0;
}
