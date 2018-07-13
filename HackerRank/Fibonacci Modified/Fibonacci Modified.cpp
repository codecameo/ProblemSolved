#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int base1,base2;

long long int fibo(int index)
{
    if(index==1)
        return base1;
    else if(index==2)
        return base2;

    long long int x=fibo(index-1);
    long long int y=fibo(index-2);

    printf("%d %lld %lld\n",index,x*x,y);

    return (x*x)+y;
}

int main() {

    int index;
    scanf("%d %d %d",&base1,&base2,&index);

    printf("%lld\n",fibo(index));
    return 0;
}

