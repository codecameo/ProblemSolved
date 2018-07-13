#include <stdio.h>
#include <vector>
#define pb push_back
using namespace std;
vector<int>v[160],res[160];
int count[160]={0},s,n;
int ser[1009];
void DP(int i,int ans,bool fg[],bool f)
{
  if(i==s){
      for(j=0;j<s;j++)
      {
          if(fg[j]==true)
          {

          }
      }
  return;
  }
  int j;
  for(j=0;j<6;j++)
  printf("%d ",fg[j]);
  puts("");
  printf("i-> %d ans-> %d f-> %d\n",i,ans,f);
  DP(i+1,ans,fg,f);
  for(j=0;j<v[i].size();j++)
  {
      fg[v[i][j]]=true;
  }
  ans^=ser[i];
  if(fg[ans]==true && f==true){
  res[ans].pb(i);
  count[ans]++;
  printf("i-> %d ans-> %d count-> %d\n",i,ans,count[ans]);
  }
  DP(i+1,ans,fg,1);
}
int main()
{
    bool flag[150]={false};
    int i,j,k,vag,xr,min,m;
    scanf("%d %d",&n,&s);
    for(i=0;i<s;i++)
    {
        scanf("%d",&k);
        for(j=0,xr=0;j<k;j++)
        {
            scanf("%d",&vag);
            v[i].pb(vag);
            xr^=vag;
            if(k==1)
            {
                res[vag].pb(i);
                count[vag]++;
            }
        }
        ser[i]=xr;
    }
    DP(0,0,flag,0);
     /*for(i=0;i<s;i++)
    {
        printf("%d ",ser[i]);
        for(j=0;j<v[i].size();j++)
        {
            printf("%d ",v[i][j]);
        }
        puts("");
    }*/
    /*for(i=0,min=999999,m=0;i<n;i++)
    {
        if(count[i]<min)
        {
            min=count[i];
            m=i;
        }
    }
    printf("%d\n",min);
    for(i=0;i<res[m].size();i++)
    printf("%d\n",res[m][i]);*/
return 0;
}
