#include <stdio.h>
int main ()
{
    int count=0,i,j,a,f,k,l;
    scanf("%d",&k);
        while(k--)
    {
        scanf("%d %d",&a,&f);
        for(l=1;l<=f;l++)
        {
            for(i=1,count=0;i>0;)
        {
            for(j=1;j<=i;j++)
            {
                printf("%d",i);
            }
            printf("\n");
            if(i==a)
            count=1;
            if(count==1)
            i--;
            else if(count==0)
            i++;
        }
        if(count==1 && i==0 && l<f)
        printf("\n");
        }
        if(k>0)
        printf("\n");

    }
    return 0;
}
