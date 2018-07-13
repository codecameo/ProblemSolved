#include <stdio.h>
int pow(int b,int p){
if(!p) return 1;
return b*pow(b,p-1);
}
int main()
{
    int n,k,x,i,j,l,flag,y;
    long long int count,num,num2;
   // for(x=0;;x++)
    //{
        scanf("%d %d",&n,&k);
        num=pow(k,n-1);
        for(i=1,num2=0;i<=n;i++)
        num2+=(k-1)*(pow(k,n-i));//printf("%lld %lld\n",num,num2);
        for(j=num,count=0;j<=num2;j++)
        {
            count++;
            for(l=j,y=0,flag=0;y<n;y++,l/=k)
            {
                if(l%k==0)
                    flag++;
                else
                flag=0;
                if(flag==2)
                {
                 break;
                }
                if(l==0)
                break;
            }
            if(flag==2)
            count--;
            //printf("%d %d %d %d %d\n",y,l,j,count,flag);
            //if(y==n && l!=0)
            //break;
        }
        printf("%lld\n",count);
    //}

    return 0;
}
