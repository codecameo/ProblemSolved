#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int main()
{
    int t,kase=1,a,b,c,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        swap(a,b);
        if(a==1)
        {
            printf("Case %d: %d\n",kase++,b);
        }
        else if(a==2)
        {
            ans=b/4;
            ans*=4;
            c=b%4;
            if(c==1)
            ans+=2;
            else if(c>1)
            ans+=4;
             printf("Case %d: %d\n",kase++,ans);
        }
        else{
        c=a*b;
        printf("Case %d: %d\n",kase++,(c+1)/2);
        }
    }
}
