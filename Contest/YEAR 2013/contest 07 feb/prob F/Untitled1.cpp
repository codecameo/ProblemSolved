#include <stdio.h>
int table[1000002];
double ar [1000002];
void seive(){
int i,j;
for(i=1;i<=1000001;i++)
table[i]=1;
for(i=2;i<=500003;i++)
for(j=i+i;j<=1000002;j+=i)
{
  table[j]+=i;
}
for(i=2;i<=1000002;i++){
ar[i]=(1.0*table[i])/(1.0*i);
}
ar[1]=0;
}
int main(){
int i,a,b,ans;
double min;
seive();
while(scanf("%d %d",&a,&b)!=EOF){
min=999999999.0;
for(i=a;i<=b;i++){
if(min>ar[i]){
min=ar[i];
ans=i;
}
}
printf("%d\n",ans);
}
return 0;
}
