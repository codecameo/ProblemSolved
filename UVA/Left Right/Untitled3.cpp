#include <stdio.h>
int main()
{
    int t,nim,a,b,x,i,n,kase=1;
    scanf("%d",&t);
    while(t--)
    {
        nim=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        x=(b-a-1);
        nim=nim^x;
        }
        if(nim>0)
        printf("Case %d: Alice\n",kase++);
        else
        printf("Case %d: Bob\n",kase++);
    }
    return 0;
}
