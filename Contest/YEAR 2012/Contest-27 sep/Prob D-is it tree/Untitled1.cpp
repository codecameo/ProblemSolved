#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int num[1000000],num2[1000000],num1[1000000],t[1000000];
int main ()
{
    int i,k,j,l,count,node,kase=0;
    bool flag,flag1;
    for(;;)
    {
        flag=0;
        memset(t,-1,sizeof(t));
        for(k=0,l=0,flag1=0;;k++,l+=2)
        {
            scanf("%d %d",&i,&j);
            if(i==-1 && j==-1)
            {
                flag1=1;
                break;
            }
            if(i==0 && j==0)
            break;
            if(i==j)
            {
                flag=1;printf("%d %d\n",i,j);
            }
           // edge++;
            num[l]=num1[k]=i;
            num[++l]=num2[k]=j;
        }
        if(flag1==1)
        break;
        if(flag==1)
        {
            printf("Case %d is not a tree.\n",++kase);
            continue;
        }
        sort(num,num+l);
        node=num[l-1];
        //printf("%d\n",node);
        for(i=0;i<k;i++)
        {
            t[num2[i]]=0;
            t[num1[i]]=0;
        }
        for(i=0;i<k;i++)
        {
            t[num2[i]]++;
            //printf("%d %d\n",i,t[num2[i]]);
        }
        for(i=0,flag=0,count=0;i<=node;i++)
        {
            if(t[i]==0)
            count++;
            if(count>1)
            flag=1;
            if(t[i]>1)
            flag=1;
            //printf("%d %d %d",t[i],flag,count);
            if(flag==1)
            break;
        }
        if(flag==1 || count==0)
        printf("Case %d is not a tree.\n",++kase);
        else
        printf("Case %d is a tree.\n",++kase);

    }

return 0;
}
