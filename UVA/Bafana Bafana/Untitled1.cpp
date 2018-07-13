#include <stdio.h>
int main ()
{
    int n,count=0,k,p,N,i;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d %d",&N,&k,&p);
        for(i=0;i<p;i++)
        {
            if(k==N)
            k=0;
            k++;
        }
        count++;
        printf("Case %d: %d\n",count,k);
    }


    return 0;
}
