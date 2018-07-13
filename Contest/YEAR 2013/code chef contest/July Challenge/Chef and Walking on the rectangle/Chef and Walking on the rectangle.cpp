#include <stdio.h>
#include <math.h>
int main()
{
    int t,n,m,k,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        if(n!=1 && m!=1)
        {
            ans=(k/2)+(k%2);
            printf("%d\n",ans);
        }
        else if((n==1 && m==1) || (n==1 && m==2) || (n==2 && m==1))
        puts("0");
        else
        printf("%d\n",k);
    }

}
