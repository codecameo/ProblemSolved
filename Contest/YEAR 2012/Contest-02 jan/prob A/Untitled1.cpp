#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int ar[1000000],num[1000000];
int main ()
{
    int i,n,sum,flag,avg;
    memset(ar,0,sizeof(ar));
    scanf("%d",&n);
    for(i=0,sum=0;i<n;i++){
    cin>>num[i];
    ar[num[i]]++;
    sum+=num[i];
    }
    avg=sum/n;
    if(avg*n!=sum){
     printf("0\n");
     return 0;
    }
    cout<<ar[avg]<<endl;
    if(ar[avg]==0)
    return 0;
    for(i=0,flag=0;i<n;i++){
     if(flag)
     printf(" ");
     if(num[i]==avg){
     printf("%d",i+1);
     flag=1;
     }
    }

    return 0;
}
