#include <stdio.h>
int main ()
{
    int T,m1,m2,d1,d2,y1,y2,i,j;
    scanf("%d",&T);
    for(i=1,j=1;i<=T;j++,i++)
    {
        printf("\n");
        scanf("%d/%d/%d",&d2,&m2,&y2);
        scanf("%d/%d/%d",&d1,&m1,&y1);
        if(y1>y2 ||(y1==y2 && m1>m2) ||(y1==y2 && m1==m2 && d1>d2))
        printf("Case #%d: Invalid birth date\n",j);
        else if(((y2-y1)==1 && m1>m2) || ((y2-y1)==1 && m1==m2 && d1>d2) || (y1==y2 && m1<m2) || (y1==y2 && m1==m2 && d2>d1))
        printf("Case #%d: 0\n",j);
        else if(y2-y1>130 && (m2>m1 ||(m1==m2 && d1<d2)))
        printf("Case #%d: Check birth date\n",j);
        else
        printf("Case #%d: %d\n",j,y2-y1);
    }

    return 0;
}
