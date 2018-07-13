#include <stdio.h>
#include <string.h>
#include <math.h>
bool table[10000000];
int prime[1000000];
void seive()
{
memset(table,false,sizeof(table));
table[0]=table[1]=true;
int i,j;
for(i=4;i<=10000000;i+=2) table[i]=true;
for(i=3;i*i<=10000000;i+=2)
if(table[i]==0)
for(j=i*i;j<=10000000;j+=i)
table[j]=true;
prime[0]=2;
for(i=3,j=0;i<10000000;i+=2)
if(table[i]==false) prime[++j]=i;
}
int main ()
{
    seive();
    int tcase,a,b,kase=0;
    unsigned long long int lcm,l,p,pro=1;
    scanf("%d",&tcase);
    while(tcase--)
    {
        scanf("%d %d %llu",&a,&b,&lcm);
        if(lcm%a!=0 || lcm%b!=0)
        {
            printf("Case %d: impossible\n",++kase);
            continue;
        }
        l=lcm;
        int i=0,c=0,d=0;
        bool x=0;
        while(l>0)
        {
            //printf(" gf ");
            if(l%prime[i]==0)
            {
                d++;
                l/=prime[i];
                if(a%prime[i]==0 || b%prime[i]==0)
                {
                    c++;
                    if(a%prime[i]==0)
                    a/=prime[i];
                    if(b%prime[i]==0)
                    b/=prime[i];
                }
                //printf("%d %d %d %d\n",a,b,l,prime[i]);
            }
            else
            {
                if(d>0)
                {
                    if(d>c)
                    {
                      p=pow(prime[i],d);
                      pro*=p;
                     // printf("%llu\n",pro);
                    }
                }
                c=0;d=0;i++;
            }
            if(x==1)
            break;
            if(l==1)
            x=1;

        }

        printf("Case %d: %llu\n",++kase,pro);
        pro=1;

}
    return 0;
}










