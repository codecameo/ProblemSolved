#include <stdio.h>
int main ()
{
    int i,c,num[100000],n,j,k=0,m,l;
    while(scanf("%d",&m)!=EOF)
    {
        for(l=0;l<m;l++)
        {
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&num[i]);
            for(i=0,k=0;i<n;i++)
            {
                for(j=i+1;j<n;j++)
                {
                    if(num[i]>num[j])
                    {
                    k++;
                    }

                }
            }
        printf("Optimal train swapping takes %d swaps.\n",k);
        }
    }
return 0;
}

