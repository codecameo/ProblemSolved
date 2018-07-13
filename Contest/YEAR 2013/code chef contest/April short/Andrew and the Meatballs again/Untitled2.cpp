#include <stdio.h>
int GCD (int i, int j){
    int r;
    while (i!=0){
        r= j%i;
        j=i;
        i=r;
    }
    return j;
}
int main()
{
    int t,n,m,i,j,k,l,flag,ar[1000];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(i=2;i<n-m;i++)
        {
            l=-1;
            for(j=i+1;j<n;j++)
            {
                flag=0;
                for(k=0;k<=l;k++)
                {
                    if(GCD(ar[k],j)==1)
                    flag=1;
                }
                if(flag!=1)
                ar[++l]=j;
                if(l==m)
                break;
            }
            if(l==m)
            break;
        }
        if(l==m)
        {
            for(i=0;i<l;i++)
            {
                if(i)
                printf(" ");
                printf("%d",ar[i]);
            }
            puts("");
        }
        else
        puts("-1");
    }
}
