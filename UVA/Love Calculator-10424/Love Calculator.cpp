#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main ()
{
  int sum1,i,l1,l2,c,sum2,ar[2];
  double love;
  char ch1[50],ch2[50];
  while(gets(ch1)!=0)
  {
      gets(ch2);
      l1=strlen(ch1);
      l2=strlen(ch2);
      for(i=0,sum1=0;i<l1;i++)
      {
              c=ch1[i];
              if(c>=65 && c<=90)
              c=c-64;
              else if(c>=97 && c<=122)
              c=c-96;
              else
              c=0;
              sum1=sum1+c;
      }
      printf("%d\n",sum1);
      if(sum1%9!=0)
      ar[0]=sum1%9;
      else
      ar[0]=9;
      for(i=0,sum2=0;i<l2;i++)
      {
              c=ch2[i];
              if(c>=65 && c<=90)
              c=c-64;
              else if(c>=97 && c<=122)
              c=c-96;
              else
              c=0;
              sum2=sum2+c;
      }
      printf("%d\n",sum2);
      if(sum2%9!=0)
      ar[1]=sum2%9;
      else
      ar[1]=9;
      printf("%d %d\n",ar[0],ar[1]);
      sort(ar,ar+2);
      love=(1.0*ar[0]/ar[1])*100;
      printf("%.2lf %%\n",love);
  }
return 0;
}
