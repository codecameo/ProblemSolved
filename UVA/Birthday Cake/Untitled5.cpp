#include<stdio.h>
int   num[200][2];
int main()
{  int i,n,j,k,count1,count2,ok;
    while(scanf("%d",&n)!=EOF&&n)
   {    ok=0;
        for(i=0;i<2*n;i++)
          scanf("%d%d",&num[i][0],&num[i][1]);
       for (i=-500;i<=500;i++)
      {   for(j=-500;j<=500;j++)
      {   count1=0;count2=0;
          for(k=0;k<2*n;k++)
           {if((i*num[k][0]+j*num[k][1])>0)
              count1++;
           else if((i*num[k][0]+j*num[k][1])<0)
               count2++;

           }
          if(count1==count2&&count1==n)
          {  ok=1;
             break;
          }

      }
         if(ok)
            break;
   }
      if (ok)
        printf("%d %d\n",i,j);


   }


   return 0;
}
