#include <stdio.h>
int main(){
int max,sum,i,ar[10010],t;
while(scanf("%d",&t)){
    if(t==0)
    break;
for(i=0,sum=0,max=0;i<t;i++){
scanf("%d",&ar[i]);
sum+=ar[i];
if(sum>max)
max=sum;
else if(sum<=0)
sum=0;
}
if(max!=0)
printf("The maximum winning streak is %d.\n",max);
else
printf("Losing streak.\n");
}
return 0;
}
