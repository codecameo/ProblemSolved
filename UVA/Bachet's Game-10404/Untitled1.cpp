#include <stdio.h>
#include <string.h>
int st[1000010];
int main ()
{
    int s[13],n,m,i,j;
    bool flag;
    while(scanf("%d",&n)!=EOF)
    {
        memset(st,0,sizeof(st));
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&s[i]);
            st[s[i]]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<m;j++)
            {
                //printf("%d %d %d %d\n",i,i-s[j],)
                if(s[j]<=i)
                if((st[i-s[j]])==0)
                 {
                     st[i]=1;
                     //printf("%d ",st[i]);
                     break;
                 }
            }
            //printf("%d ",st[i]);
        }
        if(st[n]==1)
        printf("Stan wins\n");
        else
        printf("Ollie wins\n");

    }
    return 0;
}
