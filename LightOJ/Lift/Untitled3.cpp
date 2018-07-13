#include <stdio.h>
int main()
{
    int t,kase=1,me,lift,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&me,&lift);
        if(me>lift)
        {
            ans=me-lift;
            lift=ans+me;
        }
        ans=(lift*4)+19;
        printf("Case %d: %d\n",kase++,ans);
    }
    return 0;
}
