#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <set>

using namespace std;
int wish[31][31];
bool flag;
set<int> all;
struct
{
    bool st;
    set<int> acptList;
}user[31];

void wishSet()
{
    all.clear();
    for(int i=0;i<31;i++)
    {
        user[i].st=false;
        user[i].acptList.clear();
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
        std::set<int>::iterator it;
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=k;i++)
            all.insert(i);
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                scanf("%d",&w);
                if(w>0)
                    user[i].acptList.insert(w);
                else
                {
                    for(int num=1;num<=m;num++)
                    {
                        if(num==-1*w)
                            continue;
                        else
                            user[i].acptList.insert(num);
                    }
                }
            }

            std::set<int>::iterator it2;
            for(it2= user[i].acptList.begin();it2!= user[i].acptList.end();it2++){
            printf("%d ",*it2);
        }
            puts("end");
        }




        scanf("%d",&nW);

        for(int k=0;k<nW;k++)
        {
            scanf("%d",&taken);
            for(int i=1;i<=n;i++)
            {
                it= user[i].acptList.find(taken);
                printf("%d ",*it);
                if(*it==taken)
                {
                    puts("in");
                    user[i].st=true;
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            if(user[i].st==false)
            {
                flag=false;
                break;
            }
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
