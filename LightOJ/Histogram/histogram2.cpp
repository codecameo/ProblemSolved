#include <stdio.h>
#include <stack>
#include <algorithm>
#include <string.h>
#define ps push
#define MAX 30000
using namespace std;
stack <int> s;
int val[30010],left[MAX+10],right[MAX+10];
void reset()
{
    while(!s.empty())
       s.pop();
    memset(val,0,sizeof(val));
    memset(left,0,sizeof(left));
    memset(right,0,sizeof(right));
}
int main()
{
    int i,t,kase=1,n;
    scanf("%d",&t);
    while(t--)
    {
        reset();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        s.ps(0);
        for(i=1;i<=n;i++)
        {
            while(!s.empty() && val[s.top()]>= val[i])
                s.pop();
            int v=s.top();
            left[i]=val[i]*(i-v);
            s.ps(i);
        }
        while(!s.empty())
            s.pop();
        s.ps(n+1);
        for(i=n;i>0;i--)
        {
            while(!s.empty() && val[s.top()]>= val[i])
                s.pop();
            int v=s.top();
            right[i]=val[i]*(v-i);
            s.ps(i);
        }
        int mx=-1;
        for(i=1;i<=n;i++)
        {
            mx=max(left[i]+right[i]-val[i],mx);
        }
        printf("Case %d: %d\n",kase++,mx);
    }
    return 0;
}
