#include <stdio.h>
int main ()
{
    int count=0,high_jump=0,low_jump=0,i,j,n,m,num[100000];
    scanf("%d",&n);
        while(n--)
        {
            scanf("%d",&m);
        for(j=0;j<m;j++)
            {
                scanf("%d",&num[j]);
                if(j>0)
                {
                    if(num[j-1]<num[j])
                    high_jump++;
                    if(num[j-1]>num[j])
                    low_jump++;
                }
            }
            count++;
            printf("Case %d: %d %d\n",count,high_jump,low_jump);
            high_jump=0;
            low_jump=0;
        }
return 0;
}
