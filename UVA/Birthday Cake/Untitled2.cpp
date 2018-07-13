#include <stdio.h>
int main ()
{
    int x[210],y[210],i,j,k,count1,count2,n,flag,res;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(i=0;i<2*n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
            for(i=-500,flag=0;i<=500;i++){
            for(j=-500;j<=500;j++){
            for(k=0,count1=0,count2=0;k<2*n;k++)
            {
                res=(i*x[k]+(j*y[k]));
                //printf("%d\n",res);
                if(res>0)
                count1++;
                else if(res<0)
                count2++;
            }
            //if(i==-500 && j==101)
            //printf("%d\n",count);
            if(count1==count2 && count1==n)
            {
                flag=1;
                break;
            }
            }
            if(flag==1)
            break;
            }
            printf("%d %d\n",i,j);
    }

    return 0;
}
