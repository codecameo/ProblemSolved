#include <stdio.h>
int main ()
{
    long long int i,j,k=0,a,c=1,max=0,l;
    while(scanf("%lld %lld",&a,&l)!=EOF)
    {
        if(a<0 && l<0)
        break;
      for(j=a;j>=1;)
        {
            k++;
            if(j==1)
            break;
            if(j%2==0)
            j=j/2;
            else
            j=(3*j)+1;
            if(j>l)
            break;
        }
        if(max<k)max=k;
        k=0;
    printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",c,a,l,max);
    max=0;
    c++;
    }
    return 0;
}

