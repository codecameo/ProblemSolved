#include <stdio.h>
void DP(int i,bool fg[])
{
     int j;
    if(i==3){
    //printf("%d\n",i);
    for(j=0;j<i;j++)
    printf("%d ",fg[j]);
    puts("");
    return;
    }
    //fg[i]=1;
    fg[i]=1;
    DP(i+1,fg);
    /*if(i==2){
    //printf("%d\n",i);
    for(j=0;j<=i;j++)
    printf("%d ",fg[j]);
    puts("");}*/
    fg[i]=0;
    DP(i+1,fg);
    //int j;
    //printf("%d\n",i);
    /*if(i==2){
    for(j=0;j<=i;j++)
    printf("%d ",fg[j]);
    puts("");}*/
}
int main()
{
    int i;
    bool fl[10]={false};
    DP(0,fl);
    //for(i=1;i<=5;i++)
}
