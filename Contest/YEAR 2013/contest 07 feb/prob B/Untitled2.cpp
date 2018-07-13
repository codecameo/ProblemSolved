#include <stdio.h>
int main(){
int n,x,min,max,i,num,bk,fr;
while(scanf("%d %d",&n,&x)!=EOF){
    max=1000;
    min=-1000;
for(i=0;i<n;i++)
{
    scanf("%d",&num);
    if(num<0)
    {
        if(num>min)
        min=num;
    }
    else if(num>0){
     if(num<max)
     max=num;
    }
}
if(x>0){
if(max<x){
printf("Impossible\n");
continue;
}
bk=-min+(x-min);
printf("%d %d\n",x,bk);
}
if(x<0){
if(min>x){
printf("Impossible\n");
continue;
}
fr=max+(-x+max);
printf("%d %d\n",fr,-x);
}
}
return 0;
}
