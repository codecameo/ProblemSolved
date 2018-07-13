#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int t,kase=1,ar[5],x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&ar[0],&ar[1],&ar[2]);
        sort(ar,ar+3);
        x=ar[0]*ar[0]+ar[1]*ar[1];
        if(x==ar[2]*ar[2])
            printf("Case %d: yes\n",kase++);
        else
        printf("Case %d: no\n",kase++);
    }
}
