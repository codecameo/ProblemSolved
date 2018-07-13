#include <iostream>
#include <cstdio>

using namespace std;

const int N = 205;

int w[N], b[N];

int main()
{
    int T, n, cas=1;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=0; i<n; i++)
            scanf("%d", &w[i]);
        for (int i=0; i<n; i++)
            scanf("%d", &b[i]);
        int k = 0;
        for (int i=0; i<n; i++)
            k = k^(b[i]-w[i]-1);
            printf("%d\n",k);
        printf("Case %d: %s\n", cas++, k?"white wins":"black wins");
    }
    return 0;
}
