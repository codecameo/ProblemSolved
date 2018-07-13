#include <stdio.h>
#include <iostream>
using namespace std;
int main ()
{
    int x,y,a,b,count,i,j,k,ar1[10000],ar2[10000],l;
    cin>>x>>y>>a>>b;
    if(a<=b)
    a=b+1;
    for(i=a,count=0,k=0,l=0;i<=x;i++)
    {
        for(j=b;j<i && j<=y;j++)
        {
            //printf("%d %d\n",i,j);
            ar1[k++]=i;
            ar2[l++]=j;
            count++;
        }
    }
    cout<<count<<endl;
    for(i=0;i<k;i++)
    cout<<ar1[i]<<" "<<ar2[i]<<endl;
    return 0;
}
