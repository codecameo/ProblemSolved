#include <cstdio>
//#include <cstring>
//#include <cstdlib>
#include <string>
using namespace std;

int n,a,b,c;
int aa,bb,cc;
char dig[300];

int main()
{
    while(~scanf("%d%d%d",&n,&a,&b))
    {
        scanf("%s",dig);
        c = n-a-b;
        int tot = 0;

        if(a + b > n)
        {
            printf("-1\n");
            continue;
        }

        int aa = 0,bb = 0, cc = 0;

        for(int i=0; i<n; i++)
        {
            if(dig[i] == '0')   aa++;
            if(dig[i] == '1')   bb++;
            if(dig[i] == '2')   cc++;
        }
        tot += abs(a-aa) + abs(b - bb) + abs(c-cc);

        printf("%d\n",tot/2);

        for(int i=0;dig[i];i++)
        {
            if(aa>a&&dig[i]==48)
            {
                aa--;
                if(bb<b) dig[i]=49,bb++;
                else dig[i]=50,cc++;
            }
            if(bb>b&&dig[i]==49)
            {
                bb--;
                if(aa<a) dig[i]=48,aa++;
                else dig[i]=50,cc++;
            }
            if(cc>c&&dig[i]==50)
            {
                cc--;
                if(bb<b) dig[i]=49,bb++;
                else dig[i]=48,aa++;
            }
        }
        puts(dig);

    }
    return 0;
}
