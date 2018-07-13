#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int sum=0,dis=0,a,i,num[100000],n,k,avg;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        avg=(num[0]+num[n-1])/2;
        for(i=0,dis=0;i<n;i++)
        {
            if(i>0)
            {
            a=num[i]-num[i-1];
            dis+=a;
            }
        }
        dis+=(avg-num[0])+(num[n-1]-avg);
        printf("%d\n",dis);
    }
    return 0;
}
