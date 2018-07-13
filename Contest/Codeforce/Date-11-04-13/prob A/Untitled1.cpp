#include <stdio.h>
int table[1001];
int main()
{
    int n,max=-1,a,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        table[a]++;
        if(max<table[a])
        {
            max=table[a];
        }
    }
    if(n%2==0){
    if(max<=n/2)
    printf("YES\n");
    else
    puts("NO");
    }
    else
    {
        if(max<=(n/2)+1)
          printf("YES\n");
        else
          puts("NO");
    }
    return 0;
}
