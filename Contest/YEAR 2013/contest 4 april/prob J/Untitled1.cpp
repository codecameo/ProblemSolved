#include <stdio.h>
int main()
{
    int p,n;
    while(scanf("%d",&n)!=EOF)
    {
        p=1;
        for(;p<n;)
        {
            p*=9;
            if(p>=n){
            printf("Stan wins.\n");
            continue;
            }
            p*=2;
            if(p>=n)
            {
                printf("Ollie wins.\n");
            }
        }
    }
}
