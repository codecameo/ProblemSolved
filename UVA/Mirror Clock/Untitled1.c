#include <stdio.h>
int main ()
{
    int H,M,h,c,d,m,T,i;
    scanf("%d",&T);
    for(i=1;i<=T;i++)
    {
    scanf("%d:%d",&H,&M);
    c=(H*60)+M;
    if(c==720)
    printf("12:00\n");
    else if(c>720)
    {
        d=(720*2)-c;
        h=d/60;
        m=d-(h*60);
    printf("%02d:%02d\n",h,m);
    }
    else
    {
    d=720-c;
    h=d/60;
    m=d-(h*60);
    if(h==0)
    h=12;
    printf("%02d:%02d\n",h,m);}
    }
    return 0;
}
