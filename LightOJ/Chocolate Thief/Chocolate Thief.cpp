#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
    int kase=1,t;
    int l,w,h,mx,mn,n;
    char name[300],name1[300],name2[300];
    scanf("%d",&t);
    while(t--)
    {
        mx=-1;mn=1000000;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            getchar();
            cin>>name;
            scanf("%d %d %d",&l,&w,&h);
            if(mx<l*w*h)
            {
                mx=l*w*h;
                strcpy(name1,name);
            }
            if(mn>l*w*h)
            {
                mn=l*w*h;
                strcpy(name2,name);
            }
        }
         printf("Case %d: ",kase++);
         if(mx==mn)
            puts("no thief");
         else
            printf("%s took chocolate from %s\n",name1,name2);
    }

    return 0;
}
