#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string.h>
int cl[200010];
using namespace std;
struct st{
int val,num;
friend bool operator< (st n1, st n2){
               return n1.val> n2.val;
        }
};
int main ()
{
    int n,v,i,j,dragon,coin,flag;
    char t;
    st cell;
    priority_queue<st> q;
    scanf("%d",&n);
    for(i=2;i<n;i++)
    {
        getchar();
        cin>>t>>v;
        if(t=='d'){
        cell.num=i;
        cell.val=v;
        q.push(cell);
        }
        else
        {
            if(q.size()>=v)
            while(q.size()>=v)
            q.pop();
        }
    }
    cin>>t>>v;
    dragon=q.size();
    if(dragon<v){
    printf("-1\n");
    return 0;
    }
    else
    {
        memset(cl,0,sizeof(cl));
        coin=0;
        i=0;
        while(!q.empty())
        {
            cell=q.top();
            coin+=cell.val;
            cl[cell.num]=1;
            q.pop();
        }
    }
    printf("%d\n%d\n",coin,dragon);
    flag=0;
    for(j=2;j<n;j++)
    {
        if(cl[j]==1){
        if(flag)
        printf(" ");
        printf("%d",j);
        flag=1;
        }
    }
    return 0;
}
