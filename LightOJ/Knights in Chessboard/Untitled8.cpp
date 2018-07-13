#include<stdio.h>


int main()
{
    int T,Ts,n,m,temp,ans;
    scanf("%d",&T);
    for (Ts=1;Ts<=T;Ts++)
    {
        scanf("%d%d",&n,&m);
        printf("Case %d: ",Ts);
        if (n>m)
        {
            temp=n;
            n=m;
            m=temp;
        }
        if (n==1)
            printf("%d\n",m);
        else if (n==2)
        {
            ans=(m/4)*4;
            if (m%4>=2)
                ans+=4;
            else
                ans+=(m%4)*2;
            printf("%d\n",ans);
        }
        else
            printf("%d\n",(n*m+1)/2);
    }
    return 0;
}
