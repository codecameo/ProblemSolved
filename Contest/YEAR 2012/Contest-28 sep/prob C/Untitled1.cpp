#include <stdio.h>
#include <iostream>


int p[1001], w[1001];
int f(int i,int left)
{

    if(left<0)
    return -9982;
    if(i==n+1)
    return 0;
    int ret1=p[i]+f(i+1,left-w[i]);
    int ret2=f(i+1,left);
    return max(ret1,ret2);

}
int main()
{
     int t;
     scanf("%d", &t);
     while (t--)
     {
           int ans = 0;
           int n, g;
           scanf("%d", &n);
           for (int i = 0; i < n; i++)scanf("%d %d", &p[i], &w[i]);
           scanf("%d", &g);
           int mw;
           while (g--)
           {
                  scanf("%d", &mw);
                  memset(f, 0, sizeof(f));
                  for (int i = 0; i < n; i++)
                  ans +=f(0,mw);
           }
            printf("%d\n", ans);
     }
     return 0;
}
