#include <stdio.h>
#include <string.h>

int p[100000];

void seive()
{
    int v[100000], i, j = 0, k;
    memset(v , 0, sizeof(v));
    v[0] = v[1] = 1;
    for(i = 2; i < 100000; i ++)
    {
        if(v[i] == 0)
        {
            p[j ++] = i;
            for(k = i + i; i < 1000 && k < 100000; k += i)
                v[k] = 1;
        }
    }
}

int fact(int n,int p)
{
    int ret = 0 ;

    while(n)
    {
        n /= p ;
        ret += n ;
    }

    return ret ;
}


int main()
{
    int a,tcase,num,c,i,b,kase=1;
    scanf("%d", &tcase);
    seive();
    while(tcase--)
    {
       scanf("%d",&num);
       printf("Case %d: %d = ",kase,num);
       for(i=0,b=0;p[i]<=num;i++)
       {
        c=fact(num,p[i]);
        if(c>0)
        {
            if(b)printf(" * ");
            printf("%d (%d)",p[i],c);
            b=1;
        }
       }
       printf("\n");kase++;
    }
    return 0;
}




