#include <stdio.h>
#include <string.h>
int main()
{
    int num[110],max,n,t,a,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        max=-1;
        memset(num,0,sizeof(num));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&a);
                num[a]++;
                if(num[a]>max)
                max=num[a];
            }
        }
        if(max>n)
        printf("Case %d: no\n",kase++);
        else
        printf("Case %d: yes\n",kase++);
    }
}
