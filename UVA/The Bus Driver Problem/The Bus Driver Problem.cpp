#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int n,r,d,mor[100000],eve[100000],i,j,sum=0,a,b;
    while(scanf("%d %d %d",&n,&d,&r)!=EOF)
    {
        if(n==0 && d==0 && r==0)
        break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&mor[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&eve[i]);
        }
        sort(mor,mor+n);
        sort(eve,eve+n);
        for(i=0,j=n-1,sum=0;i<n && j>=0;i++,j--)
        {
            a=mor[i]+eve[j];
            if(a>d)
            {
              b=(a-d)*r;
              sum=sum+b;
            }
        }
        printf("%d\n",sum);
        sum=0;
    }
    return 0;
}
