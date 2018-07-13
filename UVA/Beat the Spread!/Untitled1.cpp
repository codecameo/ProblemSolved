#include <stdio.h>
int main ()
{
    int n,s,d,x,y;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&s,&d);
       if(s>=d && (s+d)%2==0)
      {
        x=(s+d)/2;
        y=(s-d)/2;
        printf("%d %d\n",x,y);
      }
        else
        printf("impossible\n");

    }

    return 0;
}
