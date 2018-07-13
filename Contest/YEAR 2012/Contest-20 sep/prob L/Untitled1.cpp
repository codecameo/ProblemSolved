#include <stdio.h>
int gcd(int a, int b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main()
{
    int tcase,num,i,lcm;
    unsigned long long int sum;
    scanf("%d",&tcase);
    while(tcase--)
    {
       scanf("%d",&num);
       for(i=1,sum=0,lcm=0;i<=num;i++)
       {
           lcm=(i*num)/gcd(i,num);
           sum+=lcm;
       }
       printf("%llu\n",sum);
    }


    return 0;
}
