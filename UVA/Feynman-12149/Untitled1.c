#include <stdio.h>
int main ()
{
 int n,sum;
 while(scanf("%d",&n)!=EOF)
 {
  if(n==0)
  break;
  sum=n*(n+1)*((2*n)+1)/6;
  printf("%d\n",sum);
 }
 return 0;
}
