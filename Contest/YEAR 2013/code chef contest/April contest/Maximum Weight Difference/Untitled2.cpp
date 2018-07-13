#include <stdio.h>
#include <algorithm>
int k,n;
long long int ar[100];
int DP(int i,int s,int nw)
{
    if(k==nw)
    return s;
    if(i==n)
    return 0;
    ret1=DP(i+1,s+=ar[i],nw+1);
    ret2=DP(i+1,s,nw);
    ret1=sum-2*ret1;
    ret2=sum-2*ret2;
    return max(ret1,ret2);
}
using namespace std;
int main()
{
  long long int sum,sum1,sum2,ar[110];
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
      for(i=0,sum1=0;i<k;i++)
      {
          sum1+=ar[i];
          sum2+=ar[n-i-1];
      }
      //sum2
      sum1=sum-sum1;
      sum2=sum-sum2;
      sum-=abs(2*sum1);
      printf("%lld\n",sum);
  }
  return 0;
}
