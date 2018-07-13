#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{

    scanf("%d %d %d",&n,&t[0],&t[1]);
    sort(t,t+2);
    for(sum1=0,sum2=0,count=0,flag1=false,flag2=false;count<n;)
    {
        sum1+=t[0];
        count++;
        if(count<n)
        flag1=true;
        else
        flag1=false;
        if(sum2+t[1]>sum1+t[0])
        continue;
        if(count>=n)
        break;
        sum2+=t[1];
        count++;
        if(count<n)
        flag2=true;
        else
        flag2=false;
    }
    if(flag1==true)
    {
    count++;
    }
    if(flag2==true)
    count++;


}
