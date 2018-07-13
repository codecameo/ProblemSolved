#include <stdio.h>
int main ()

{

    int n,i,j;

    while ( scanf ("%d", &n) != EOF )
    {
        int a [1000 + 5];

        for ( i = 0; i < n; i++ )

            scanf ("%d", &a [i]);
        int cnt = 0;

        for ( i = 0; i < n; i++ ) {
            for ( j = i + 1; j < n; j++ )
                if ( a [i] > a [j] ) cnt++;
        }

        printf ("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
