#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int kase=1,t;
    long long int d;
    char num[300];
    scanf("%d",&t);
    while(t--)
    {
        getchar();
        cin>>num;
        scanf("%lld",&d);
        printf("Case %d: ",kase++);
        long long int res=0,l;
        l=strlen(num);
        int i= 0;
        if(num[0]=='-')
            i++;
        for(;i<l;i++)
        {
            res=res*10+num[i]-'0';
            //printf("%lld\n",d);
            res=res%d;
        }
        if(res==0)
            puts("divisible");
        else
            puts("not divisible");
    }

    return 0;
}
