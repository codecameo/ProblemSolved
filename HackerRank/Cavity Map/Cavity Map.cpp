#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool isCavity(int center,int x,int y,int z,int w)
{
    int m = max(x,y);
    int n = max(z,w);
    int k = max(m,n);
    return (center>k);

}

int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++){
       cin >> grid[grid_i];
    }

    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            //printf("%d ",isCavity(grid[i][j],grid[i-1][j],grid[i+1][j],grid[i][j-1],grid[i][j+1]));
            if(isCavity(grid[i][j],grid[i-1][j],grid[i+1][j],grid[i][j-1],grid[i][j+1]))
            {
                grid[i][j]='X';
            }
        }
        //printf("\n");
    }

    for(int grid_i = 0;grid_i < n;grid_i++){
       cout<< grid[grid_i]<<endl;
    }

    return 0;
}
