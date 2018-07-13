#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[10000][10000],n;
int st1[1000000],st2[1000000];
int res()
{
 int i,j;
 for(i=0;i<=n;i++){
 dp[i][0]=0;
 dp[0][i]=0;
 }
 for(i=1;i<=n;i++){
 for(j=1;j<=n;j++){
  if(st1[i-1]==st2[j-1])
   dp[i][j]=dp[i-1][j-1]+1;
   else
   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
 }
 }
 return dp[n][n];
}

int main(){
int num,i;
scanf("%d",&n);
for(i=1;i<=n;i++){
scanf("%d",&num);
st1[num-1]=i;
}
while(scanf("%d",&num)!=EOF){
memset(st2,0,sizeof(st2));
st2[num-1]=1;
for(i=2;i<=n;i++){
scanf("%d",&num);
st2[num-1]=i;
}
printf("%d\n",res());
}
return 0;
}
