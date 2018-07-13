#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findPair(int nCount,int num[],int diff)
{
    int res=0;

    for(int i=0,j=1;i<nCount && j<nCount;)
    {
        if(num[j]-num[i]>=diff)
        {
            if(num[j]-num[i]==diff)
                res++;

            i++;
            if(i==j)
                j++;
        }
        else
        {
            j++;
        }
    }


    return res;
}


int main()
{
    int n,diff;
    int values[100001];

    scanf("%d %d",&n,&diff);

    for( int i = 0 ; i < n; i++ )
    {
        scanf("%d",&values[i]);
    }

    qsort(values, n, sizeof(int), cmpfunc);

    int res = findPair(n,values,diff);

    printf("%d\n",res);

   return 0;
}
