#include <stdio.h>
int main()
{
    int t,kase=1,me,lift,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&me,&lift);
        if(me>lift)
        lift+=me;
        ans=(lift*4)+19;
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}

