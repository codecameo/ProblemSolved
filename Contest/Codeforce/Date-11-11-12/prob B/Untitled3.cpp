#include <stdio.h>
int main ()
{
    int ar1[100010],ar2[100010],i,max,min,count,tcase,num[100001],k=0;
    scanf("%d",&tcase);
    for(i=0;i<tcase;i++)
    {
        scanf("%d %d",&ar1[i],&ar2[i]);
        if(!i)
        {
          max=ar2[i];
          min=ar1[i];
          count=i;
          num[k++]=i;
        }
        if(min>=ar1[i]){
        min=ar1[i];
        count=i;
        num[k++]=i;
        }
        if(max<ar2[i]){
          max=ar2[i];
        }
    }
    //printf("%d %d %d\n",min,max,k);
        for(i=0;i<k;i++){
        if(ar2[num[i]]==max && ar1[num[i]]==min){
         printf("%d\n",num[i]+1);
         break;
        }
        }
         if(i==k)
         printf("-1\n");
    return 0;
}
