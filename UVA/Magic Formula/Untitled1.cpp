#include <stdio.h>
int main ()
{
    int a,b,c,d,L,i,m,count=0;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&L)!=EOF)
    {
        if(a==0 && b==0 && c==0 && d==0 && L==0)
        break;
      for(i=0;i<=L;i++)
      {
          m=(a*(i*i))+(b*i)+c;
          if(m%d==0)
          count++;
      }
        printf("%d\n",count);
        count=0;
    }


    return 0;
}
