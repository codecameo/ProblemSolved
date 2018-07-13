#include<stdio.h>
int main ()
{
    int v,t,s;
    double a;
    while(scanf("%d %d",&v,&t)==1)
  {
    if(t==0)
    s=0;
    else
    {
         a=1.0*v/t;
    s=1.0*a*t*t*4/2;
    }
    printf("%d\n",s);
  }

    return 0;
}
