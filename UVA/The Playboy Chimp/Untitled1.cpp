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
if(val>num[n-1])
{
    printf("%d X\n",num[n-1]);
    continue;
}
else if(val==num[n-1]){
printf("%d X\n",num[n-2]);
continue;
}
else if(val<num[0])
{
    printf("X %d\n",num[0]);
    continue;
}
else if(val==num[0])
{
    printf("X %d\n",num[1]);
    continue;
}
for(st=0,end=n-1,mid=(st+end)/2;;)
{
    printf("%d st %d mid %d end\n",num[st],num[mid],num[end]);
    if(st>end){
        printf("%d %d\n",num[end],num[st]);
        break;
    }
    if(num[mid]==val)
    {
        m=mid-1;
        for(;m>=0;m--){
         if(num[m]!=val){
         printf("%d ",num[m]);
         break;
        }
        }
        x=mid+1;
        for(;x<n;x++)
        if(num[x]!=val){
        printf("%d\n",num[x]);
        break;
        }
        break;
    }
    if(val>num[mid])
    {
        st=mid+1;
        mid=(st+end)/2;
    }
    else if(val<num[mid]){
     end=mid-1;
     mid=(st+end)/2;
    }
}
}
}
//freopen("output.txt","w",stdout);
return 0;
}
