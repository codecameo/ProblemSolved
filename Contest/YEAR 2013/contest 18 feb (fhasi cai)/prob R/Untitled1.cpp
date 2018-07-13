#include <stdio.h>
#include <string.h>
int dp[210][210],ar[210][210],w,n;
int DP(int x,int y)
{
    if(x==w && y==n)
    {
        return dp[x][y]=1;
    }
    if(x>w || y>n)
    return 0;
    if(ar[x][y]==1)
    return 0;
    if(dp[x][y])
    return dp[x][y];
    if(ar[x][y]==0)
    return dp[x][y]=DP(x+1,y)+DP(x,y+1);
}

int main(){
int t,i,j,c=0;
char st[1000];
scanf("%d",&t);
while(t--)
{
    memset(ar,0,sizeof(ar));
    memset(dp,0,sizeof(dp));
    scanf("%d %d",&w,&n);
    getchar();
    for(i=0;i<w;i++)
    {
        gets(st);
        //puts(st);
        int x=0,y=0;
        bool flag=0;
        for(j=0;j<=strlen(st);j++)
        {
            if(st[j]!=' ' && j<strlen(st))
            y=(y*10)+(st[j]-'0');
            else{
            //printf("%d\n",y);
            if(flag==0){
            x=y;
            //printf("%dx\n",x);
            flag=1;
            }
            else
            {
                //printf("%dy\n",y);
                ar[x][y]=1;
            }
            y=0;
            }
        }
    }
    if(c++)
    printf("\n");
    //DP(1,1);
    printf("%d\n",DP(1,1));
}
return 0;
}
