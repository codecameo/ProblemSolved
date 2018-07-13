#include <stdio.h>
int main ()
{
    int i,c,num[100000],n,j,k=0;
    while(scanf("%d",&n)!=EOF)
    {
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
        printf("Minimum exchange operations : %d\n",k);

    }


    return 0;
}
