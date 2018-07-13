#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;
int d[15][15],visit[15][15];
struct data{
int x,y;
}start,end;
void bfs()
{
    int i,j;
    memset(visit,0,sizeof(visit));
    memset(d,-1,sizeof(d));
    for(i=1;i<=8;i++)
    for(j=1;j<=8;j++)
    d[i][j]=0;
 data u1,u2,u3,u4,u5,u6,u7,u8;
 d[start.x][start.y]=0;
 visit[start.x][start.y]=1;
    queue<data>q;
    q.push(start);
    while(!q.empty())
    {
        data top=q.front();
        //printf("%d %d\n",top.x,top.y);
        q.pop();
        u1.x=(top.x)+2; u1.y=(top.y)-1;//printf("%d %d\n",u1.x,u1.y);
        if(u1.x>0 && u1.y>0)
        if(d[u1.x][u1.y]>=0 && visit[u1.x][u1.y]!=1)
        {
           // printf("%d %d\n",u1.x,u1.y);
            q.push(u1);
            d[u1.x][u1.y]=d[top.x][top.y]+1;
            visit[u1.x][u1.y]=1;
        }
        u2.x=(top.x)+2; u2.y=(top.y)+1;//printf("%d %d\n",u2.x,u2.y);
        if(u2.x>0 && u2.y>0)
        if(d[u2.x][u2.y]>=0 && visit[u2.x][u2.y]!=1)
        {
            q.push(u2);
            d[u2.x][u2.y]=d[top.x][top.y]+1;
            visit[u2.x][u2.y]=1;
        }
        u3.x=(top.x)-2; u3.y=(top.y)-1;//printf("%d %d\n",u3.x,u3.y);
        if(u3.x>0 && u3.y>0)
        if(d[u3.x][u3.y]>=0 && visit[u3.x][u3.y]!=1)
        {
            q.push(u3);
            d[u3.x][u3.y]=d[top.x][top.y]+1;
            visit[u3.x][u3.y]=1;
        }
        u4.x=(top.x)-2; u4.y=(top.y)+1;//printf("%d %d\n",u4.x,u4.y);
        if(u4.x>0 && u4.y>0)
        if(d[u4.x][u4.y]>=0 && visit[u4.x][u4.y]!=1)
        {
            q.push(u4);
            d[u4.x][u4.y]=d[top.x][top.y]+1;
            visit[u4.x][u4.y]=1;
        }
        u5.x=(top.x)+1; u5.y=(top.y)-2;//printf("%d %d\n",u5.x,u5.y);
        if(u5.x>0 && u5.y>0)
        if(d[u5.x][u5.y]>=0 && visit[u5.x][u5.y]!=1)
        {
            q.push(u5);
            d[u5.x][u5.y]=d[top.x][top.y]+1;
            visit[u5.x][u5.y]=1;
        }
        u6.x=(top.x)-1; u6.y=(top.y)-2;//printf("%d %d\n",u6.x,u6.y);
        if(u6.x>0 && u6.y>0)
        if(d[u6.x][u6.y]>=0 && visit[u6.x][u6.y]!=1)
        {
            q.push(u6);
            d[u6.x][u6.y]=d[top.x][top.y]+1;
            visit[u6.x][u6.y]=1;
        }
        u7.x=(top.x)+1; u7.y=(top.y)+2;//printf("%d %d\n",u7.x,u7.y);
        if(u7.x>0 && u7.y>0)
        if(d[u7.x][u7.y]>=0 && visit[u7.x][u7.y]!=1)
        {
            q.push(u7);
            d[u7.x][u7.y]=d[top.x][top.y]+1;
            visit[u7.x][u7.y]=1;
        }
        u8.x=(top.x)-1; u8.y=(top.y)+2;//printf("%d %d\n",u8.x,u8.y);
        if(u8.x>0 && u8.y>0)
        if(d[u8.x][u8.y]>=0 && visit[u8.x][u8.y]!=1)
        {
            q.push(u8);
            d[u8.x][u8.y]=d[top.x][top.y]+1;
            visit[u8.x][u8.y]=1;
        }
      if(d[end.x][end.y]!=0)
      break;
    }
}

int main ()
{
    char st1[3],st2[3],ch[5];
    //int i,j;
    strcpy(ch,"from");
  while(scanf("%s",st1)!=EOF)
    {
        scanf("%s",st2);
        start.x=st1[0]-96;
        start.y=st1[1]-'0';
        end.x=st2[0]-96;
        end.y=st2[1]-'0';
       // printf("%d %d %d %d\n",start.x,start.y,end.x,end.y);
        bfs(); //printf("%d %d %d %d\n",start.x,start.y,end.x,end.y);
        /*for(i=0;i<=9;i++)
        {
        for(j=0;j<=9;j++)
        printf("%d ",d[i][j]);
        printf("\n");
        }*/
        printf("To get %s %s to %s takes %d knight moves.\n",ch,st1,st2,d[end.x][end.y]);

    }
 return 0;
}
