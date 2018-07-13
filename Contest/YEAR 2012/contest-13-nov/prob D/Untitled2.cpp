#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main()
{
int n,a1,b1,c1,i;
int a2,b2,c2;
char pas[210];
    scanf("%d %d %d",&n,&a1,&b1);

        scanf("%s",pas);
        c1=n-a1-b1;
        int chg= 0;

        if(a1+b1>n)
        {
            printf("-1\n");
            return 0;
        }

        a2=0;
        b2=0;
        c2=0;
        for(i=0; i<n; i++)
        {
            if(pas[i] == '0')   a2++;
            if(pas[i] == '1')   b2++;
            if(pas[i] == '2')   c2++;
        }
        chg += abs(a1-a2) + abs(b1-b2) + abs(c1-c2);

        printf("%d\n",chg/2);

        for(int i=0;pas[i];i++)
        {
            if(a2>a1&&pas[i]==48)
            {
                a2--;
                if(b2<b1) pas[i]=49,b2++;
                else pas[i]=50,c2++;
            }
            if(b2>b1&&pas[i]==49)
            {
                b2--;
                if(a2<a1) pas[i]=48,a2++;
                else pas[i]=50,c2++;
            }
            if(c2>c1&&pas[i]==50)
            {
                c2--;
                if(b2<b1) pas[i]=49,b2++;
                else pas[i]=48,a2++;
            }
        }
        puts(pas);

    return 0;
}
