#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    long long int a[3],i;
    int k;
    for(k=1;;k++)
    {
        for(i=0;i<3;i++)
        scanf("%lld",&a[i]);
        if(a[0]==0 && a[1]==0 && a[2]==0)
        break;
        sort(a,a+3);
     if(a[2]*a[2]==(a[0]*a[0])+(a[1]*a[1]))
     printf("right\n");
     else
     printf("wrong\n");
    }
     return 0;
}
