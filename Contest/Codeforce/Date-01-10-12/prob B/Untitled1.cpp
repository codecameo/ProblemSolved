#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
bool isprime(long long int a)
{
int n,i;
n=sqrt(a);
 for(i=2;i<n;i++)
   {
     if(a%i==0)
     return false;
    }
    return true;
}
int main()
{
    long long int num[100010],sq;
    long long int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>num[i];
    }
    for(i=0;i<n;i++)
    {
        if(num[i]==1)
         {
            printf("NO\n");
            continue;
         }
        sq=sqrt(num[i]);
        if(sq*sq!=num[i])
        {
            printf("NO\n");
            continue;
        }
        if(isprime(num[i])==true)
         printf("YES\n");
         else
        printf("No\n");

    }
return 0;
}
