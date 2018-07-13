#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    int num[10]={0},ct,count,dig;
    long long int n,i,j;
    cin>>n;
    if(n==0){
     printf("1\n");
     return 0;
    }
    if(n<102){
    printf("%lld\n",n);
    return 0;
    }
    for(i=102,ct=0;i<=n;i++)
    {
        memset(num,0,sizeof(num));
        for(j=i,count=0;j>0;j/=10)
        {
            //printf("%lld\n",i);
            dig=j%10;
            if(num[dig]==0){
            num[dig]=1;
            count++;
            if(count==3)
            break;
            }
        }
        //printf("%dc\n",count);
            if(count<=2){
            ct++;
            //if(i>120)
            //i+=10;
           // cout<<i<<endl;
            }
    }
    printf("%d\n",ct+101);
}
