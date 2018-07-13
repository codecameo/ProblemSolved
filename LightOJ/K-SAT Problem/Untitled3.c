#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
int wish[31][31];
bool flag;

struct
{
    int wish[31];
    int state;
    bool st;
}user[31];

void wishSet()
{
    flag=true;
    for(int i=0;i<31;i++)
    {
        user[i].st=false;
        user[i].state=2;
        for(int j=0;j<32;j++)
            user[i].wish[j]=0;
    }
}

int main()
{
    int kase=1,t;
    int m,n,k,w,nW,taken;
    char name[300],name1[300],name2[300];
    scanf("%d",&t);
    while(t--)
    {
        wishSet();
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&w);
                if(w>0)
                {
                    user[i].wish[w]=1;
                    if(user[i].state==2 || user[i].state==1)
                        user[i].state=1;
                    else
                        user[i].state=0;
                }
                else
                {
                    user[i].wish[-1*w]=-1;
                    if(user[i].state==2 || user[i].state==-1)
                        user[i].state=-1;
                    else
                        user[i].state=0;
                }
            }
        }

        scanf("%d",&nW);

        for(int k=0;k<nW;k++)
        {
            int val;
            scanf("%d",&taken);
            for(int i=1;i<=n;i++)
            {
                val= user[i].wish[taken];
                /*if(val==-1)
                    user[i].wish[0]=0;
                if(val==1 || (val==0 && user[i].wish[0]==1))
                    user[i].st=true;*/

                /*if(val==1)
                {
                    user[i].wish[0]=1;
                    user[i].st=true;
                }
                else if(val==0)
                {

                }
                else if(val==-1)
                {
                    if(user[i].wish[0]==0)
                    user[i].wish[0]=-1;
                    else if(user[i].wish[0]==-1)
                    user[i].wish[0]=1;
                    printf("%d\n",user[i].wish[0]);
                }*/

                if(user[i].state==-1)
                    user[i].wish[0]=1;
            }
        }

        for(int i=1;i<=n;i++)
            if(user[i].wish[0]==-1)
            {
                flag=false;
                break;
            }

        if(nW==0)
        flag=true;
        printf("Case %d: ",kase++);
        if(flag==true)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
