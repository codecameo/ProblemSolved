#include <stdio.h>
#include <iostream>
int n,num[10000];
using namespace std;
int dp(int j,int t)
{
    int res,res1;
    if(t==0){
    printf("Yes\n");
    return 1;
    }
    if(j>n)
    return 0;
    res=dp(j+1,t-=num[j+1]);
    res1=dp(j+1,t);
    return max(res,res1);

}
int main ()
{
    int tg,i,tcase,ans;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d",&tg,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        ans=dp(0,tg);
        if(ans==1)
        printf("YES\n");
        if(ans==0)
        printf("NO\n");
    }
    return 0;
}
