#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int kase=1,r1,c1,r2,c2,p1,p2,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        printf("Case %d: ",kase++);
        p1=(r1+c1)%2;
        p2=(r2+c2)%2;
        if(p1!=p2)
        {
            puts("impossible");
            continue;
        }
        p1=fabs(c1-c2);
        p2=fabs(r1-r2);
        if(p1==p2)
            puts("1");
        else
            puts("2");
    }

    return 0;
}
