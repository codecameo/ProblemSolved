#include <stdio.h>
#include <string.h>
int p[1010];
void divisor()
{
    memset(p,0,sizeof(p));
    int i,j;
    for(i=1;i<=1000;i++)
    {
        for(j=i;j<=1000;j+=i)
        p[j]++;
    }
}

int main()
{
    int a,i,j,k,num[1010],kase=1,tcase;
    scanf("%d",&tcase);
    while(tcase--){
    scanf("%d",&a);
    divisor();
    //printf("%d ",p[12]);
    for(i=1,k=1;i<=1000;k++)
    {
        for(j=1000;j>0;j--)
        if(p[j]==k)
        {
            num[i]=j;
            i++;
        }
    }
    printf("Case %d: %d\n",kase,num[a]);
    kase++;
    }
    return 0;
}

