#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int dp[10000][10000],l1,l2;
char st1[1000000],st2[1000000];
void res()
{
 int i,j;
 l1=strlen(st1);
 l2=strlen(st2);
 for(i=0;i<=l1;i++){
 dp[i][0]=0;
 dp[0][i]=0;
 }
 for(i=1;i<=l1;i++){
 for(j=1;j<=l2;j++){
  if(st1[i-1]==st2[j-1])
   dp[i][j]=dp[i-1][j-1]+1;
   else
   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
 }
 }
 /*for(i=1;i<=l1;i++){
 for(j=1;j<=l2;j++){
  printf("%d ",dp[i][j]);
 }
 printf("\n");
 }*/
}

int main(){

while(gets(st1)!=NULL){
gets(st2);
res();
printf("%d\n",dp[l1][l2]);
}
}
