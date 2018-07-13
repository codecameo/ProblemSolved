#include <stdio.h>
#include <math.h>
int prime(int a)
{
    int n,k,j,i;
    n=sqrt(a);
    for(i=1,j=0,k=0;i<=n;i++)
         {
               if(a%i==0)
               k++;
               if(a==(n*n) && k==0)
               {
                   j++;
                   k--;
               }
               if(k>1)
               {
                    return 0;
               }
           }
    return 1;
}
int main ()
{
    int num,pri1,pri2,i;
    while(scanf("%d",&num)!=EOF)
  {
             if(num==0)
             break;
             for(i=3;i<=num/2;i+=2)
             {
                 pri1=prime(i);
                 pri2=prime(num-i);
                 if(pri1==1 && pri2==1)
                 {
                     printf("%d = %d + %d\n",num,i,num-i);
                     break;
                 }
             }
    if(i>num/2)
		printf("Goldbach's conjecture is wrong.\n");

  }
    return 0;
}
