#include <stdio.h>
int main ()
{
    int i,num,n,sum,kase=0,m,red,blue,gre;
    long long int count;
    while(scanf("%d",&num) && num)
    {
           count=0;
           red=1;
           blue=2;
           gre=3;
           for(sum=0;sum<num;red++,blue++,gre++)
           {
               sum=red+gre+blue;
               //printf("a. %d %d %d %d\n",red,blue,gre,sum);
               if(sum>num)
               break;
           for(sum=0;sum<num;blue++,gre++)
           {
               sum=red+blue+gre;
               if(sum>num)
               break;
               else
               count++;
              // printf("b. %d %d %d %d\n",red,blue,gre,count);
               if(sum==num)
               break;
           }
           blue=red+1;gre=red+2;
           sum=0;
           //printf("c. %d %d %d\n",red,blue,gre);
           }
          /* red=2;blue=3;gre=4;
           for(sum=0;sum<num;red++,blue++,gre++)
           {
              sum=red+blue+gre;
               if(sum>num)
               break;
               else
               count++;
               if(sum==num)
               break;
           }*/



        printf("Case %d: %lld\n",++kase,count);
    }


    return 0;
}
