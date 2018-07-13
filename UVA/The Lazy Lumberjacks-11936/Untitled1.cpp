#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int num[3],i,n,j;
    while(scanf("%lld",&n)!=EOF)
    {
    for(j=0;j<n;j++)
       {
        for(i=0;i<3;i++)scanf("%lld",&num[i]);
        sort(num,num+3);
        if((num[0]+num[1])<=num[2])
        printf("Wrong!!\n");
        else
        printf("OK\n");
       }
    }

    return 0;
}
