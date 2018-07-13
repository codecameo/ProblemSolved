#include <stdio.h>
int main(){
int st,mid,end,m,n,x,i,num[50010],val,a,y;
while(scanf("%d",&n)!=EOF){
for(i=0;i<n;i++){
scanf("%d",&num[i]);
}
scanf("%d",&a);
for(y=0;y<a;y++){
scanf("%d",&val);
for(i=0,m=-1;i<n;i++)
{
    if(val>num[i])
    m=num[i];
    else
    break;
}
if(m==-1)
printf("X ");
else
printf("%d ",m);
for(i=n-1,x=-1;i>=0;i--)
{
    if(val<num[i])
    x=num[i];
    else
    break;
}
if(x==-1)
printf("X\n");
else
printf("%d\n",x);
}
}
//freopen("output.txt","w",stdout);
return 0;
}
