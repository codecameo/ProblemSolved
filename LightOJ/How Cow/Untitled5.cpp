#include <stdio.h>
int main()
{
    int t,kase=1,n,i,x1,y1,x2,y2,x,y;
    scanf("%d",&t);
    while(t--)
    {
       printf("Case %d:\n",kase++);
       scanf("%d %d %d %d %d",&x1,&y1,&x2,&y2,&n);
       for(i=0;i<n;i++)
       {
          scanf("%d %d",&x,&y);
          if(y>=y1 && y<=y2 && x<=x2 && x>=x1)
          puts("Yes");
          else
          puts("No");
       }
    }

    return 0;
}
