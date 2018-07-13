

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define N 1000000
#define LL long long
using namespace std;

int matrix [100 + 5] [100 + 5];

int main ()
{
    int m, n;

    while ( scanf ("%d %d", &m, &n) ) {
        if ( m == 0 && n == 0 ) break;

        int input;

        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                scanf ("%d", &input);
                matrix [i] [j] = 1 - input;
            }
        }
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                printf ("%d ",matrix[i][j]);
                //matrix [i] [j] = 1 - input;
            }
            printf("\n");
        }
        printf("\n\n\n");

        for ( int i = 1; i < m; i++ ) {
            for ( int j = 0; j < n; j++ )
                if ( matrix [i] [j] == 1 ) matrix [i] [j] = matrix [i - 1] [j] + 1;
        }
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                printf ("%d ", &matrix[i][j]);
                //matrix [i] [j] = 1 - input;
            }
            printf("\n");
        }
        int maxi = -1;
        for ( int i = 0; i < m; i++ ) {
            for ( int j = 0; j < n; j++ ) {
                int cnt = matrix [i] [j];
                for ( int k = j + 1; k < n && matrix [i] [j] <= matrix[i] [k]; k++ )
                    cnt += matrix [i] [j];
                for ( int k = j - 1; k >= 0 && matrix [i] [j] <= matrix [i] [k]; k-- )
                    cnt += matrix [i] [j];
                if ( cnt > maxi) maxi = cnt;
            }
        }

        printf ("%d\n", maxi);
    }

    return 0;
}
