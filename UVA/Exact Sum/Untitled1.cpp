#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int n,m,i,j,num[10000]={0},min,a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&num[i]);
        sort(num,num+n);
        scanf("%d",&m);
        for(i=0,min=1000000;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(num[i]+num[j]==m)
                {
                    c=num[j]-num[i];
                    if(c<min)
                    {
                        min=c;
                        a=num[i];
                        b=num[j];
                    }
                }

            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",a,b);
    }


    return 0;
}
