#include <stdio.h>
#include <math.h>
int main ()
{
    int N,M;
    int i,j,c,b,d,e,f,sum;
    unsigned long long int ar1[1000000000000000000000000000000],ar2[1000000000000000000000000000000],ar3[1000000000000000000000000000000],ar4[1000000000000000000000000000000];
    while(scanf("%d %d",&N,&M)!=EOF)
    {
    for(i=N,j=0;i>0;i=i/2,j++)
    {
     b=(i%2);
     ar1[j]=b;
     c=j;
    }

    for(i=M,j=0;i>0;i=i/2,j++)
    {
     b=(i%2);
     ar2[j]=b;
     d=j;
    }

        for(l=0;l<=c || l<=d;l++)
        {
            ar3[l]=ar1[l]+ar2[l];
            if(ar3[l]==2)
            ar3[l]=0;
        }

        for(i=0,j=l-1;i<=l;i++,j--)
        ar4[i]=ar3[j];
        sum=0;
        for(j=0,i=0;j<l;j++,i++)
    {
        e=pow(2,j);
        f=ar4[i]*e;
        sum=sum+f;
    }
    printf("%d\n",sum);
     }

    return 0;
}
