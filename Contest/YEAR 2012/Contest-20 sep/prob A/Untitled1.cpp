#include <stdio.h>
#include <math.h>
bool isprime(long long int a)
{
int n,i;
n=sqrt(a);
 for(i=2;i<=n;i++)
   {
     if(a%i==0)
     return false;
    }
    return true;
}

int main ()
{
    long long int num;
    int k,i,x,fr;
    bool c;
    for(k=0;;k++)
    {
        scanf("%llu",&num);
        if(num==0)
        break;
        if(isprime(num)==true)
        {
            printf("-1\n");
            continue;
        }
    x=sqrt(num);
    for(i=2,c=0;i<=x;i++)
    {
       if(num%i==0)
       {
        if(isprime(num/i)==true)
        {
            c=1;
            printf("%llu\n",num/i);
            break;
        }
           if(isprime(i)==true)
           fr=i;
       }
    }
    if(c==0)
    printf("%d\n",fr);
    }
return 0;
}
