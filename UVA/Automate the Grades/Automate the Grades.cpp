#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int sum,kase=1,c,ct[3],t1,t2,f,a,n;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&f,&a,&ct[0],&ct[1],&ct[2]);
        sort(ct,ct+3);
        c=(ct[1]+ct[2])/2;
        sum=t1+t2+f+a+c;
        if(sum>=90)
        printf("Case %d: A\n",kase);
        else if(sum>=80 && sum<90)
        printf("Case %d: B\n",kase);
        else if(sum>=70 && sum<80)
        printf("Case %d: C\n",kase);
        else if(sum>=60 && sum<70)
        printf("Case %d: D\n",kase);
        else if(sum<60)
        printf("Case %d: F\n",kase);
        kase++;
    }
    return 0;
}
