#include <stdio.h>
int main ()
{
    int k,num[10],i,count=0;
    scanf("%d",&k);
    printf("Lumberjacks:\n");
    while(k--)
    {
        for(i=0;i<10;i++)
        {
            scanf("%d",&num[i]);
            if(i>0)
            {
                if(num[i-1]<num[i])
                count++;
            }
        }
        if(count==9 || count==0)
        printf("Ordered\n");
        else
        printf("Unordered\n");
        count=0;
    }

    return 0;
}
