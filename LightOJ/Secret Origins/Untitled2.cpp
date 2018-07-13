#include <stdio.h>
int count=0,len;
long long int mask;
void set0(int k)
{
    mask=mask xor 1<<k;
    //printf("%lld\n",mask);
}
void set1(int k)
{
     mask=mask | 1<<k;
}
void check(int k)
{
    if(((mask & 1<<k)==0) && count!=0)
    {
        set1(k);
        len=k;
        return;
    }
    else if((mask & 1<<k)!=0)
    {
       count++;
       set0(k);
       check(k+1);
    }
    else if(((mask & 1<<k)==0) && count==0)
    {
        check(k+1);
    }
}
int main()
{
    int t,kase=1,i;
    //long long int n;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%lld",&mask);
        check(0);
        for(i=0;i<count-1;i++)
        {
            set1(i);
        }
        printf("Case %d: %lld\n",kase++,mask);
    }
}
