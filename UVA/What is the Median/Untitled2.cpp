#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int i=0,num[100000]={0},a,n;
    while(scanf("%lld",&n)!=EOF)
    {
       if(i==10000)break;
        num[i]=n;
        sort(num,num+(i+1));
        if(i%2==0)
        printf("%lld\n",num[i/2]);
        else
        {
            a=(num[i/2]+num[(i/2)+1])/2;
            printf("%lld\n",a);
        }
        i++;
    }

    return 0;
}
