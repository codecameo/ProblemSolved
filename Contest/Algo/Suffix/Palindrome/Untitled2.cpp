# include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 300055
#define MAXLG 30
char A[MAXN],b[MAXN];
struct entry {
int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, stp, cnt;
int cmp(struct entry a, struct entry b)
{
return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp(int x,int y)
{
    int ret=0;
    if(x==y)
    {
        return N-x;
    }
    for(int k=stp-1;(k>=0)&&(x<N)&&(y<N);k--)
    {
        //printf("%d %d %d\n",k,P[k][x],P[k][y]);
        if(P[k][x]==P[k][y])
        {
            //printf("%d %d\n",x,y);
            x+=(1<<k);
            y+=(1<<k);
            ret+=(1<<k);
            //printf("%d %d\n\n\n",x,y);
        }
    }
    return ret;
}
void suf()
{
    int i;
    for (N = strlen(A), i = 0; i < N; i ++)
    P[0][i] = A[i] - 'a';
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
    {
        for (i = 0; i < N; i ++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
    sort(L, L + N, cmp);
    for (i = 0; i < N; i ++)
    P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
}
}
int main()
{
int sor[MAXN],len,i;
gets(A);
    int index=0,ans=0,j;
    len=strlen(A);
    for(i=len-1,j=0;i>=0;i--)
    b[j++]=A[i];
    b[j]='\0';
    strcat(A,"#");
    strcat(A,b);
   // puts(A);
    suf();
    for(i=0;i<N;i++)
        sor[P[stp-1][i]]=i;
        index=3*len+1;
    for(i=0;i<N-1;i++)
    {
         int u=lcp(sor[i],sor[i+1]);
         int mx=max(sor[i],sor[i+1]);
         int mn=min(sor[i],sor[i+1]);
         if(mx>len && mn<len)
         {
             //printf("%d %d\n",u,sor[i]);
             if(sor[i]+sor[i+1]+u!=2*len+1)
                continue;
             if(u>ans){
             //printf("%d %d %d\n",u,sor[i],sor[i+1]);
             ans=u;
             index=mn;
             }
             else if(u==ans)
             {
                 index=min(index,mn);
             }
         }
    }
    if(ans==1){
        printf("%c\n",A[0]);
        return 0;
    }
    for(i=index;i<index+ans;i++)
    printf("%c",A[i]);
    puts("");

return 0;
}
