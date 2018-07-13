#include <stdio.h>
int main()
{
    int k,n,i,num[1000],tcase=1,a=0,b=0,balance;
    for(k=0;;k++)
    {
        scanf("%d",&n);
        if(n==0)
        break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]==0)
            a++;
            else
            b++;
        }
        balance=b-a;
        printf("Case %d: %d\n",tcase,balance);
        b=0;
        a=0;
        tcase++;
    }

    return 0;
}
