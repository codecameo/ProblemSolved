#include <stdio.h>
#include <string.h>
int main(){
int num[110][110],sum,max,i,j,k,n;
while(scanf("%d",&n)==1){
memset(num,0,sizeof(num));
for(i=1;i<=n;i++)
for(j=1;j<=n;j++){
scanf("%d",&num[i][j]);
num[i][j]+=num[i-1][j];
}
max=num[1][1];
for(i=0;i<=n;i++)
for(j=i+2;j<=n;j++){
sum=0;
for(k=1;k<=n;k++){
if(sum<0)
sum=0;
else sum+=num[j][k]-num[i][k];
if(sum>max)
max=sum;
}
}
printf("%d\n",max);
}
return 0;
}
