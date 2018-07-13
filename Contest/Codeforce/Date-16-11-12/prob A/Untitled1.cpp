#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <iostream>
#include <string>
#define sf scanf
#define pf printf
using namespace std;


int main()
{
    int ar[1000]={0},n,num,i,j,k,ch[50][50],l;
    cin>>n>>num;
     for(i=0;i<num;i++){
     sf("%d",&ch[i][0]);
     ar[ch[i][0]]=1;
     }
     /*for(i=1;i<=4;i++)
     pf("%di %da ",i,ar[i]);*/
     l=n*num;
     for(i=1,k=1,j=0;i<=l;i++)
     {
         if(ar[i]==0){
            // pf("%d %d %d\n",i,j,k);
         ch[j++][k]=i;
         if(j==num){
         j=0;
         k++;
         }
         }
     }
     for(i=0;i<num;i++){
     for(j=0;j<n;j++)
     pf("%d ",ch[i][j]);
     pf("\n");
     }

    return 0;
}
