#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int a[105];

int main()
{
    int i, t, n, dig, sum, zz = 1;
    bool flag;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        dig = sum = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            dig ^= a[i];
            sum += a[i];
        }
        if(sum == n)
        {
            if(sum & 1) flag = false;
            else flag = true;
        }
        else
        {
            if(dig == 0) flag = false;
            else flag = true;
        }

        printf("Case %d: ", zz++);
        if(!flag) printf("Bob\n");
        else printf("Alice\n");
    }

    return 0;
}
