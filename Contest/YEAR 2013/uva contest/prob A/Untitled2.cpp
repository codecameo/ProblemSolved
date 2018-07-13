#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
int i,j,k,r,s,ra[100],sa[100];
double max,ans,ar[1000];
while(scanf("%d",&r))
{
    if(r==0)
    break;
    max=0.0;
    scanf("%d",&s);
    for(i=0;i<r;i++)
    scanf("%d",&ra[i]);
    for(i=0;i<s;i++)
    scanf("%d",&sa[i]);
    for(i=0,k=0;i<r;i++)
    {
        for(j=0;j<s;j++)
        {
            ar[k++]=(1.0*sa[j])/(1.0*ra[i]);
        }
    }
    sort(ar,ar+k);
    for(i=0;i<k-1;i++){
     ans=ar[i+1]/ar[i];
     if(ans>max)
     max=ans;
    }
    printf("%.02lld\n",max);
    //cout<<fixed<<setprecision(2)<<round(max*100)/100<<endl;
}
return 0;
}
