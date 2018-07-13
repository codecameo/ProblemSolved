#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int mem[510][30001],gp[30001];
int main()
{
    int n,m,k,i,j,count,x,s,t,visit[510],sev[30010];
    queue <int> q;
    while(scanf("%d %d",&n,&m))
    {
        if(m==0 && n==0)
          break;
        memset(visit,0,sizeof(visit));
        memset(sev,0,sizeof(sev));
      count=0;
      for(i=0;i<m;i++)
      {
          scanf("%d",&k);
          gp[i]=k;
          for(j=0;j<k;j++)
          {
             scanf("%d",&mem[i][j]);
          }
      }
      sev[0]=1;
      q.push(0);
      while(!q.empty())
      {
          s=q.front();
        for(i=0;i<m;i++)
        {
            if(visit[i]==1)
             continue;
            for(j=0;j<gp[i];j++)
            {
                if(mem[i][j]==s)
                {
                    visit[i]=1;
                    for(x=0;x<gp[i];x++)
                    {
                        if(mem[i][x]!=s && sev[mem[i][x]]==0)
                        {
                          q.push(mem[i][x]);
                          sev[mem[i][x]]=1;
                        }
                    }
                }
            }
        }
        //printf("%d ",q.front());
        q.pop();
        count++;
      }
      printf("%d\n",count);
    }
    return 0;
}
