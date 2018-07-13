#include <stdio.h>
#include <string.h>
int main()
{
    int t,i,nim,n,kase=1;
    bool flag=0;
    long long int num;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        for(i=0,nim=0;i<n;i++)
        {
            scanf("%lld",&num);
            nim^=num;
            if(num>1)
            flag=1;
        }
        if(flag==0)
        {
            if(n%2==0)
               printf("Case %d: Alice\n",kase++);
            else
             printf("Case %d: Bob\n",kase++);

             continue;
        }
        if(nim!=0)
        printf("Case %d: Alice\n",kase++);
        else
        printf("Case %d: Bob\n",kase++);
    }
    return 0;
}
