#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
bool res[10010];
int ar[51];
int main()
{
    int i,n,s,j;
    while(scanf("%d %d",&s,&n)!=EOF)
    {
        memset(res,false,sizeof(res));
        for(i=0;i<n;i++)
        scanf("%d",&ar[i]);
        sort(ar,ar+n);
        res[0]=true;
        for(i=1;i<=s;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i-ar[j]<0)
                break;
                if(res[i-ar[j]]==false)
                {
                    res[i]=true;
                    break;
                }
            }
        }
        /*for(i=0;i<=s;i++)
        printf("%d-> %d\n",i,res[i]);
        puts("");*/
        if(!res[s]) printf("2\n");
    else printf("1\n");
    }
    return 0;
}
