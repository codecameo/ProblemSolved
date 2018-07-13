#include <stdio.h>
#include <string.h>
long long int ar1[1000000],ar2[1000000];
int main(){
long long int max1=-1,max2=-1,n,q;
int r,i;
char st[100];
scanf("%lld %lld",&n,&q);
while(q--){
scanf("%s %d %d",st,&r,&i);
if(strcmp(st,"RowAdd")==0){
ar1[r]+=i;
if(ar1[r]>max1)
max1=ar1[r];
}
else
{
ar2[r]+=i;
if(ar2[r]>max2)
max2=ar2[r];
}
}
printf("%lld\n",max1+max2);
return 0;
}
