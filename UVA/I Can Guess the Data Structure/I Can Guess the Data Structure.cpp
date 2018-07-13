#include <stdio.h>
#include <string.h>
#include <algorithm>
long long int ar[100000],ar1[100000];
using namespace std;
int main ()
{
    long long int n,x,y,q,p,a,b,c,d,s,i,com,num;
    memset(ar,0,sizeof(ar));
    memset(ar1,0,sizeof(ar1));
    while(scanf("%lld",&n)!=EOF)
    {
        for(i=0,x=-1,c=0,s=0,q=0,a=0,b=0,d=0,p=0,y=0;i<n;i++)
        {
            scanf("%lld %lld",&com,&num);
            if(com==1)
            {
                x++;
                ar[x]=num;
                ar1[x]=num;
            }
            else if(com==2)
            {
                //printf("%d\n",x);
                d++;
                 if(c==0)
                {
                  sort(ar1,ar1+(x+1));
                    if(num!=ar1[x])
                    c=1;
                    else
                    {
                        ar1[x]=-1;
                        p++;
                    }
                }
                if(a==0)
                {
                    //printf("%d\n",ar[x]);
                    if(ar[x]!=num)
                    a=1;
                    else
                    {
                        x--;
                        s++;
                    }
                    //printf("%da %dx\n",a,x);
                }
                if(b==0)
                {
                    if(ar[y]!=num)
                    b=1;
                    else
                    {
                       ar[y]=0;
                        y++;
                        q++;
                    }
                }
            }
        }
        //printf("%d %d %d %d\n",d,p,s,q);
            if(q==d && p!=d && s!=d)
            printf("queue\n");
            else if(s==d && p!=d && q!=d)
            printf("stack\n");
            else if(p==d && s!=d && q!=d)
            printf("priority queue\n");
            else if(q!=d && s!=d && p!=d)
            printf("impossible\n");
            else
            printf("not sure\n");
    }
    return 0;
}
