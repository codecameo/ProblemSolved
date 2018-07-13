#include <stdio.h>
#include <string.h>
int main(){
int n,i,group,num,ar[20001];
scanf("%d",&n);
memset(ar,0,sizeof(ar));
//ar[0]=1;
for(i=0,group=0;i<n;i++)
{
    scanf("%d",&num);
    ar[num]=1;
    if(ar[num-1]==1 && ar[num+1]==1)
    group--;
    else if(ar[num-1]==0 && ar[num+1]==0)
    group++;
    printf("%d\n",group);
}
printf("Justice\n");
return 0;
}
