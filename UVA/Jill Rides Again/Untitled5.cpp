#include <stdio.h>
int main(){
int tcase,sum,ans,i,val,s,start,end,st,kase=1;
scanf("%d",&tcase);
while(tcase--){
sum=0;ans=0,start=0;end=0;st=0;
scanf("%d",&s);
for(i=1;i<s;i++){
scanf("%d",&val);
sum+=val;
if(sum<0){
sum=0;
start=i;
continue;
}
else if((sum>ans) || (sum==ans && st-1==start)){
st=start+1;
ans=sum;
end=i+1;
}
}
if(ans)
printf("The nicest part of route %d is between stops %d and %d\n",kase++,st,end);
else
printf("Route %d has no nice parts\n",kase++);
}
return 0;
}
