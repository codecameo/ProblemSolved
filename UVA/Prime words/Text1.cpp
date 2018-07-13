#include <stdio.h>
#include <math.h>
#include <string.h>
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
    // if(k==1)
    //printf("yes\n");
    return 1;

}

int main()
{
  int l,i,c,a,sum;
  char ch[1000];
  memset(ch,NULL,sizeof(ch));    
  while(gets(ch)!=0)  
    {
        l=strlen(ch);
        for(i=0,sum=0;i<l;i++)
        {
            a=ch[i];
            if(a>=97)
            sum=sum+a-96;
            else
            sum=sum+a-38;
        }
        c=prime(sum);
        if(c==1)
        printf("It is a prime word.\n");
        else if(c==0)
        printf("It is not a prime word.\n");
    }
    
    
    return 0;
}



