#include <stdio.h>
#include <math.h>
int main ()
{
    int n,min,v[100000],t[100000],i,ans,c;
   // double c;
    while(scanf("%d",&n)&& n)
    {
        for(i=0,min=999999;i<n;i++)
        {
            scanf("%d %d",&v[i],&t[i]);
            if(t[i]<0)
            continue;
            c=ceil(4.5/(1.0*v[i])*3600.0);
            c=c+t[i];
            ans=c;
           // printf("%d\n",c);
            if(c<min)
            min=c;
        }
        printf("%d\n",min);

    }


}
