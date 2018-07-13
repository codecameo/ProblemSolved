#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int a[4],i,n,k;
    scanf("%d",&n);
   for(k=1;k<=n;k++)
   {
        for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+4);
    if(a[3]<(a[0]+a[1]+a[2]))
    {
        if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
        printf("square\n");
        else if(a[0]==a[1] && a[2]==a[3] && a[1]!=a[2])
        printf("rectangle\n");
        else
        printf("quadrangle\n");
    }
    else
    printf("banana\n");
    }

  return 0;
}
