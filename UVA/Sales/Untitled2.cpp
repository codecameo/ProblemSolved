#include <iostream>
#include <stdio.h>
using namespace std;
int main ()
{
    int k,n,i,j,num[10000],count=0;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        for(i=0,count=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            if(i>0)
            {
                for(j=0;j<i;j++)
                if(num[j]<=num[i])
                count++;
            }
        }
        cout<<count<<endl;
        //printf("%d\n",count);
    }
    return 0;
}
