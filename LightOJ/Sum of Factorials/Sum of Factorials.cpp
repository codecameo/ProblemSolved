#include <stdio.h>
long long int fact[30],num;
int len;
bool flag;
void ft()
{
    int i;
    fact[0]=1;
    for(i=1;i<=20;i++)
        fact[i]=i*fact[i-1];
}
int main()
{
    ft();
    int kase=1,i,t,a[30];
    scanf("%d",&t);
    while(t--)
    {
        flag=false;
        scanf("%lld",&num);
        //printf("%lld\n",num);
        int cnt=-1;
        for(i=20;i>=0;i--)
        {
            if(fact[i]<=num)
            {
                a[++cnt]=i;
                num-=fact[i];
                if(num==0)
                {
                    flag=true;
                    printf("Case %d: ",kase++);
                    for(int j=cnt;j>=0;j--)
                    {
                        printf("%d!",a[j]);
                        if(j>0)
                        printf("+");
                    }
                    puts("");
                    break;
                }
            }
        }
        if(flag==true)
        continue;
        printf("Case %d: ",kase++);
        if(flag==false)
        puts("impossible");
    }
    return 0;
}
