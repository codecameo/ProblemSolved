#include <stdio.h>

int main()
{
long int N;
      while(scanf("%ld",&N)==1)
          {
            if(N>=0&&N<=210000000)
            printf("%ld\n",(N*N+N+2)/2);
            if(N<0)
            break;
          }
return 0;
}
