#include<stdio.h>
long long ans[77]={1,1,2,2,3,4};
int main()
{
    int i;
    for (i=6; i<77;i++)
    ans[i]=ans[i-2]+ans[i-3];
    while(scanf("%d",&i)!=EOF)
    printf("%lld\n",ans[i]);
    return 0;
}
