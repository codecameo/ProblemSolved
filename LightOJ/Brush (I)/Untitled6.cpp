#include <stdio.h>
int main()
{
    int kase=1,t,n,i,s,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0,ans=0;i<n;i++)
        {
            scanf("%d",&s);
            if(s<0)
            s=0;
            ans+=s;
        }
        printf("Case %d: %d\n",kase++,ans);
    }
}
