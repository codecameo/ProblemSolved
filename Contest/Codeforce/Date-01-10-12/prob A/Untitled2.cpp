#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
struct data
{
    int x,y;
};
bool compare( data a, data b ) {
    if( a.x == b.x )
    return a.y > b.y;
    else return a.x < b.x;
}
int main ()
{
    data ar[10010];
    int s,n,i,x[10000],y[10000],j;
    bool flag;
    scanf("%d %d",&s,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&ar[i].x,&ar[i].y);
    }
    sort(ar,ar+n,compare);
    for(i=0,flag=0;i<n;i++)
    {
        if(s>ar[i].x)
        s+=ar[i].y;
        else
        {
            flag=1;
            break;
        }//printf("%d %d\n",ar[i].x,ar[i].y);
    }
    if(flag==1)
    printf("NO\n");
    else
    printf("YES\n");
    return 0;
}
