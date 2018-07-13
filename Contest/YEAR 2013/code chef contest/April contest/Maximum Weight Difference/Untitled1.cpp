#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
  long long int sum,sum1,sum2,ar[110],ans;
  int n,k,t,i;
  scanf("%d",&t);
  while(t--)
  {
      scanf("%d %d",&n,&k);
      for(i=0,sum=0;i<n;i++)
      {
          scanf("%lld",&ar[i]),sum+=ar[i];
      }
      sort(ar,ar+n);
      for(i=0,sum1=0,sum2=0;i<k;i++)
      {
          sum1+=ar[i];
          sum2+=ar[n-i-1];
      }
      sum2=sum-sum2;
      ans=min(sum1,sum2);
      ans=sum-2*ans;
      printf("%lld\n",ans);
  }
  return 0;
}
