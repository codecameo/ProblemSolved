#include <stdio.h>
void DP(int i,bool fg[])
{
    if(i==3)
    return;
    int j;
    for(j=0;j<=2;j++)
    printf("%d ",fg[j]);
    puts("");
    DP(i+1,fg);
    fg[i]=1;
    DP(i+1,fg);
}
int main()
{
    int i;
    bool fl[10]={false};
    DP(0,fl);
    //for(i=1;i<=5;i++)
}
