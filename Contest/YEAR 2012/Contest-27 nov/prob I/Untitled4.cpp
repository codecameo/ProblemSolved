#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m;
char text[18];

int main()
{
    int tt;
    scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 18; i++)
            text[i] = '0';
        for (int i = n - m + 1; i <= n; i++)
            text[i] = '1';
        do
        {
            for (int i = 1; i <= n; i++)
                printf("%c", text[i]);
            printf("\n");
        } while (next_permutation(&text[1], &text[n + 1]));
        if (tt)printf("\n");
    }
    return 0;
}
