#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std ;
int dis[1000] = {0} ;
struct node
{
    int u , v , w ;
} ;
node edge[100] ;
int n , e  , x , y;
int par[100] = {0} ;
bool ballman(int s )
{
    int i  , j;
    for(i = 0 ; i < 100 ; i++)dis[i] = 1000 ;
    dis[s] = 0 ;
    for(i = 1 ; i <= n ; i++)
    {
        for(j = 0 ; j < e ; j++)
        {
            if(dis[edge[j].u] + edge[j].w < dis[edge[j].v])
            {
                dis[edge[j].v] = dis[edge[j].u] + edge[j].w ;
                par[edge[j].v] = edge[j].u ;
            }
        }
    }
    for(i=0; i<e; i++)
    {
        if(dis[edge[i].v] > dis[edge[i].u]+edge[i].w)
        {
            x = edge[i].v ;
            y = edge[i].u ;
            return false;
        }

    }
    return true;
}
int main()
{
    int i ;
    vector<int>out ;
    scanf("%d %d" , &n , &e) ;
    for(i = 0 ; i < e ; i++)
    {
        scanf("%d %d %d", &edge[i].u , &edge[i].v , &edge[i].w) ;
    }
   if(ballman(1))
   {

        int u = n ;
        while(u != 0)
        {
            out.push_back(u) ;
            u = par[u] ;
        }
        reverse(out.begin() , out.end()) ;
        for(i = 0 ; i < out.size() ; i++)printf("%d " , out[i]) ;
        printf("\nnegative cycle not found\n") ;
    }
    else
    {
        printf("Negative cycle found\n") ;

    }
}
