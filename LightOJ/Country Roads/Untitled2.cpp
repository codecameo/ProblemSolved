#include<cstdio>
#include<queue>
#include<vector>

#define MAXX 511
#define MAXN 16011
#define inf 32767

short T,t;
short n,m,s,i,j,l;
short wt[MAXX],mat[MAXX][MAXX],k;
bool done[MAXX];

struct node
{
    short a;
}tt;

inline bool operator<(const node &a,const node &b)
{
    return a.a>b.a;
}

std::priority_queue<node>q;

int main()
{
    scanf("%hd",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%hd %hd",&n,&m);
        for(i=0;i<n;++i)
        {
            done[i]=false;
            wt[i]=inf;
            for(j=0;j<n;++j)
                mat[i][j]=inf;
            mat[i][i]=0;
        }
        while(m--)
        {
            scanf("%hd %hd %hd",&i,&j,&k);
            mat[i][j]=std::min(mat[i][j],k);
            mat[j][i]=mat[i][j];
        }
        scanf("%hd",&s);
        wt[s]=0;
        tt.a=s;
        q.push(tt);
        while(!q.empty())
        {
            i=q.top().a;
            if(done[i])
                continue;
            q.pop();
            for(j=0;j<n;++j)
                if(!done[j] && mat[i][j]<inf && wt[j]>std::max(wt[i],mat[i][j]))
                {
                    wt[j]=std::max(wt[i],mat[i][j]);
                    tt.a=j;
                    q.push(tt);
                }
        }
        printf( "Case %hd:\n", t);
        for(i=0;i<n;++i)
        {
            if( wt[i] == inf)
                printf( "Impossible\n");
            else
                printf( "%hd\n", wt[i]);
        }
    }
    return 0;
}
