#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int i,j,k=0,a,b,max=0,num[2],c,d;
    while(scanf("%lld %lld",&num[0],&num[1])!=EOF)
    {
    c=num[0];
    d=num[1];
    sort(num,num+2);
    a=num[0];
    b=num[1];
    for(i=a;i<=b;i++)
    {
       for(j=i;j>=1;)
        {
            k++;
            if(j==1)
            break;
            if(j%2==0)
            j=j/2;
            else
            j=(3*j)+1;
        }
        if(max<k)max=k;
        k=0;
    }
    printf("%lld %lld %lld\n",c,d,max);
    max=0;
    }
    return 0;
}
