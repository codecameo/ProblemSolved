#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[11], Ans[11];
int len, n, V[11]={0};
void permute(int deep)
{
    if(deep == len)
    {
        Ans[deep] = '\0';
        puts(Ans);
        return ;
    }
    char last = '#';
    for(int i = 0; i < len; i++)
    if(V[i] == 0 && last != str[i])
    {
        V[i] = 1;
        last = str[i];
        Ans[deep] = str[i];
        permute(deep+1);
        V[i] = 0;
    }
}


int main()
{
    while(scanf("%d", &n) == 1)
    {
        gets(str);
        while(n--)
        {
            gets(str);
            len = strlen(str);
            sort(str, str+len);
            permute(0);
            puts("");
        }
    }
    return 0;
}
