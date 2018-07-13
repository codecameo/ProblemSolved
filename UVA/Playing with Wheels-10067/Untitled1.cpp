#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int d[15][15][15][15],visit[15][15][15][15];
struct data{
int w,x,y,z;
}start,end,fb;
void bfs()
{
 data u1,u2,u3,u4,u5,u6,u7,u8;
 d[start.w][start.x][start.y][start.z]=0;
 visit[start.w][start.x][start.y][start.z]=1;
    queue<data>q;
    q.push(start);
    while(!q.empty())
    {
        data top=q.front();
        //printf("%d %d %d %d\n",top.w,top.x,top.y,top.z);
        q.pop();
        u1.w=(top.w)+1; u1.x=top.x; u1.y=top.y; u1.z=top.z;//printf("%d %d %d %d\n",u1.w,u1.x,u1.y,u1.z);
        if(u1.w==10)
        u1.w=0;
        if(d[u1.w][u1.x][u1.y][u1.z]>=-1 && visit[u1.w][u1.x][u1.y][u1.z]!=1)
        {
           // printf("%d %d %d %d\n",u1.w,u1.x,u1.y,u1.z);
            q.push(u1);
            d[u1.w][u1.x][u1.y][u1.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u1.w][u1.x][u1.y][u1.z]=1;
        }
        u2.w=(top.w)-1; u2.x=top.x; u2.y=top.y; u2.z=top.z;//printf("%d %d\n",u1.x,u1.y);
        if(u2.w==-1)
        u2.w=9;
        if(d[u2.w][u2.x][u2.y][u2.z]>=-1 && visit[u2.w][u2.x][u2.y][u2.z]!=1)
        {
           // printf("%d %d %d %d\n",u2.w,u2.x,u2.y,u2.z);
            q.push(u2);
            d[u2.w][u2.x][u2.y][u2.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u2.w][u2.x][u2.y][u2.z]=1;
        }
        u3.w=top.w; u3.x=(top.x)+1; u3.y=top.y; u3.z=top.z;//printf("%d %d\n",u1.x,u1.y);
        if(u3.x==10)
        u3.x=0;
        if(d[u3.w][u3.x][u3.y][u3.z]>=-1 && visit[u3.w][u3.x][u3.y][u3.z]!=1)
        {
            //printf("%d %d %d %d\n",u3.w,u3.x,u3.y,u3.z);
            q.push(u3);
            d[u3.w][u3.x][u3.y][u3.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u3.w][u3.x][u3.y][u3.z]=1;
        }
        u4.w=top.w;u4.x=(top.x)-1; u4.y=top.y;u4.z=top.z;//printf("%d %d\n",u1.x,u1.y);
        if(u4.x==-1)
        u4.x=9;
        if(d[u4.w][u4.x][u4.y][u4.z]>=-1 && visit[u4.w][u4.x][u4.y][u4.z]!=1)
        {
            //printf("%d %d %d %d\n",u4.w,u4.x,u4.y,u4.z);
            q.push(u4);
            d[u4.w][u4.x][u4.y][u4.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u4.w][u4.x][u4.y][u4.z]=1;
        }
        u5.w=top.w;u5.x=top.x; u5.y=(top.y)+1;u5.z=top.z;//printf("%d %d\n",u1.x,u1.y);
        if(u5.y==10)
        u5.y=0;
        if(d[u5.w][u5.x][u5.y][u5.z]>=-1 && visit[u5.w][u5.x][u5.y][u5.z]!=1)
        {
            //printf("%d %d %d %d\n",u5.w,u5.x,u5.y,u5.z);
            q.push(u5);
            d[u5.w][u5.x][u5.y][u5.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u5.w][u5.x][u5.y][u5.z]=1;
        }
        u6.w=top.w;u6.x=top.x; u6.y=(top.y)-1;u6.z=top.z;//printf("%d %d\n",u1.x,u1.y);
        if(u6.y==-1)
        u6.y=9;
        if(d[u6.w][u6.x][u6.y][u6.z]>=-1 && visit[u6.w][u6.x][u6.y][u6.z]!=1)
        {
            //printf("%d %d %d %d\n",u6.w,u6.x,u6.y,u6.z);
            q.push(u6);
            d[u6.w][u6.x][u6.y][u6.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u6.w][u6.x][u6.y][u6.z]=1;
        }
        u7.w=top.w;u7.x=top.x; u7.y=top.y;u7.z=(top.z)-1;//printf("%d %d\n",u1.x,u1.y);
        if(u7.z==-1)
        u7.z=9;
        if(d[u7.w][u7.x][u7.y][u7.z]>=-1 && visit[u7.w][u7.x][u7.y][u7.z]!=1)
        {
            //printf("%d %d %d %d\n",u7.w,u7.x,u7.y,u7.z);
            q.push(u7);
            d[u7.w][u7.x][u7.y][u7.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u7.w][u7.x][u7.y][u7.z]=1;
        }
        u8.w=top.w;u8.x=top.x; u8.y=top.y;u8.z=(top.z)+1;//printf("%d %d\n",u1.x,u1.y);
        if(u8.z==10)
        u8.z=0;
        if(d[u8.w][u8.x][u8.y][u8.z]>=-1 && visit[u8.w][u8.x][u8.y][u8.z]!=1)
        {
            //printf("%d %d %d %d\n",u8.w,u8.x,u8.y,u8.z);
            q.push(u8);
            d[u8.w][u8.x][u8.y][u8.z]=d[top.w][top.x][top.y][top.z]+1;
            visit[u8.w][u8.x][u8.y][u8.z]=1;
        }
      if(d[end.w][end.x][end.y][end.z]!=-1)
      break;
    }
}

int main ()
{
    int tcase,n,i;
  scanf("%d",&tcase);
  while(tcase--)
    {
      memset(d,-1,sizeof(d));
      memset(visit,0,sizeof(visit));
      scanf("%d %d %d %d",&start.w,&start.x,&start.y,&start.z);
      scanf("%d %d %d %d",&end.w,&end.x,&end.y,&end.z);
      scanf("%d",&n);
      for(i=0;i<n;i++)
      {
        scanf("%d %d %d %d",&fb.w,&fb.x,&fb.y,&fb.z);
          visit[fb.w][fb.x][fb.y][fb.z]=1;
      }
      bfs();
      printf("%d\n",d[end.w][end.x][end.y][end.z]);
    }
 return 0;
}
