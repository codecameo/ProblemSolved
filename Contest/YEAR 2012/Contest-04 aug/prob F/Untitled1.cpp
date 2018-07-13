#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int n,m,kase=0,num[10000],num1[10000],i,j;
    bool flag;
    while(scanf("%d %d",&n,&m) &&n &&m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&num1[i]);
        }
        sort(num,num+n);
        printf("CASE# %d:\n",++kase);
        for(i=0;i<m;i++)
        {
            for(j=0,flag=0;j<n && num1[i]>=num[j];j++)
            {
                if(num1[i]==num[j])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            printf("%d found at %d\n",num1[i],j+1);
            else
            printf("%d not found\n",num1[i]);
        }
    }

    return 0;
}
