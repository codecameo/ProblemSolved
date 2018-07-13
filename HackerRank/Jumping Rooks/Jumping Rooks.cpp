#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
const int inf = 300000001;
bool stop;

void print(int rockBoard[51][51])
{
    printf("\n");
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",rockBoard[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int backTrack(int x,int y,int rockboard[51][51],int rockNumber)
{
    if(!stop)
    printf("%d %d %d\t",x,y,rockNumber);

    bool isTopSet = false, isLeftSet = false;

    if(rockboard[x][y] == -1)
    {
        //printf("%d\n",rockboard[x][y]);
        rockboard[0][y] = 0;
        rockboard[x][0] = 0;
        return inf;
    }
    else if(rockNumber < k && x == n && y == n)
    {
        return inf;
    }
    else if(rockNumber == k)
    {
        return  rockboard[x][0] + rockboard[0][y] ;
    }



    int result = 0;

    if(rockboard[0][y] == 0)
    {
        rockboard[0][y] = 1;
        isTopSet = true;
    }
    else {
        result++;
    }

    if(rockboard[x][0] == 0)
    {
        rockboard[x][0] = 1;
        isLeftSet = true;
    }
    else{
        result++;
    }

    int j = y+1, res = inf;

    for(int i=x;i<=n;i++)
    {
        for(;j<=n;j++)
        {
            //print(rockboard);
            int m = backTrack(i,j,rockboard,rockNumber+1);
            //print(rockboard);

            //printf("Rock num %d res %d got %d\n",rockNumber,res,m);
            res = min(res,m);
        }
        j=1;
    }

    if(isTopSet)
    {
        rockboard[0][y] = 0;
    }

    if(isLeftSet)
    {
        rockboard[x][0] = 0;
    }

    result += res;
    return result;
}

int main() {

    int rockBoard[51][51];
    char ch;

    scanf("%d %d",&n,&k);
    getchar();

    for(int i=1; i<=n; i++)
    {
        rockBoard[0][i]=0;
        rockBoard[i][0]=0;
    }

    for(int i=1; i<=n; i++)
    {
        char board[51];
        scanf("%s",&board);
        for(int j=0; j<n; j++)
        {
            if(board[j] == '#')
                rockBoard[i][j+1] = -1;
            else if(board[j] == '.')
                rockBoard[i][j+1] = 0;
        }
    }

    int res = inf;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int m = backTrack(i,j,rockBoard,1);
            printf("1 res %d got %d\n",res,m);
            res = min(res,m);
            if(res <= 3)
            stop = true;
        }
    }


    printf("%d\n",res);

    return 0;
}
