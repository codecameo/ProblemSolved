#include <stdio.h>
int main()
{
    int w[101],b[101],i,com,t,kase=1,ans,a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&com);
        for(i=0;i<com;i++)
        {
            scanf("%d",&w[i]);
        }
        for(i=0;i<com;i++)
        {
            scanf("%d",&b[i]);
        }
        ans=0;
        for(i=0;i<com;i++)
        {
            a=b[i]-w[i]-1;
            ans=ans^a;
        }
        printf("Case %d: ",kase++);
        //printf("%d\n",ans);
        if(ans>0)
        puts("white wins");
        else
        puts("black wins");
    }
    return 0;
}
