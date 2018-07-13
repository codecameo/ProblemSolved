#include <stdio.h>
int main ()
{
    int N,i,num[100],max,T,k;
    scanf("%d",&T);
    for(k=1;k<=T;k++)
    {
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        scanf("%d",&num[i]);
    }
    max=0;
    for(i=0;i<N;i++)
    {
        if(max<num[i])
        max=num[i];
    }
    printf("Case %d: %d\n",k,max);
}
    return 0;
}
