#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
    bool vis[10010],flag1,flag2,f1,f2;
    int t,i,j,k,l,row,col,num[101][101],kase=1,ar[10010],count;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        scanf("%d %d",&row,&col);
        if(row==1 || col==1)
        {
            printf("Case #%d: YES\n",kase++);
        }
        for(i=0,k=0;i<row;i++)
        {
            for(j=0;j<col;j++)
            {
                scanf("%d",&num[i][j]);
                if(vis[num[i][j]]==false)
                {
                    ar[k++]=num[i][j];
                    vis[num[i][j]]=true;
                }
            }
        }
        flag1=false;
        sort(ar,ar+k);
        for(i=0,count=0;i<k;i++)
        {
            flag2=false;
            if(count<=2)
            {
                if(ar[i]==num[0][0])
                {
                    flag2=true;
                    count++;
                    f1=f2=false;
                    if(num[0][col-1]==ar[i])
                    {
                        for(j=1;j<col-1;j++)
                        if(num[0][j]>ar[i])
                        f1=true;
                    }
                    else
                    f1=true;
                    if(num[row-1][0]==ar[i])
                    {
                     for(j=1;j<row-1;j++)
                        if(num[j][0]>ar[i])
                        f2=true;
                    }
                    else
                    f2=true;
                    if(f1==true && f2==true)
                    flag1=true;
                    //printf("1-> %d\n",flag1);
                }
                if(flag1==true)
                break;
                if(ar[i]==num[row-1][col-1])
                {
                    flag2=true;
                    count++;
                    f1=f2=false;
                    if(num[0][col-1]==ar[i])
                    {
                        for(i=1;i<col-1;i++)
                        if(num[0][i]>ar[i])
                        f1=true;
                    }
                    else
                    f1=true;
                    if(num[row-1][0]==ar[i])
                    {
                     for(i=1;i<row-1;i++)
                        if(num[i][0]>ar[i])
                        f2=true;
                    }
                    else
                    f2=true;
                    if(f1==true && f2==true)
                    flag1=true;
                   // printf("2-> %d\n",flag1);
                }
                if(flag1==true)
                break;
            }
            for(j=0;j<row;j++)
            {
                if(num[j][0]==ar[i])
                { //printf("%d %d %d\n",num[j][0],num[j][col-1],ar[i]);
                    flag2=true;
                    if(num[j][col-1]>ar[i])
                    {
                        flag1=true;
                        //printf("hhd %d\n",flag1);
                        break;
                    }
                    for(l=0;l<col;l++)
                    {
                        if(num[j][l]>ar[i])
                        {
                            flag1=true;
                            //printf("hd%d\n",flag1);
                            break;
                        }
                    }
                   // printf("3-> %d\n",flag1);
                    if(flag1==true)
                    break;
                }
            }
            for(j=0;j<col;j++)
            {
               if(num[0][j]==ar[i])
                {
                    flag2=true;
                    if(num[row-1][j]>ar[i])
                    {
                        flag1=true;
                        break;
                    }
                    for(l=0;l<row;l++)
                    {
                        if(num[l][j]>ar[i])
                        {
                            flag1=true;
                            break;
                        }
                    }
                    //printf("4-> %d\n",flag1);
                    if(flag1==true)
                    break;
                }
            }
            if(flag2==false)
            flag1=true;
            //printf("5-> %d\n",flag1);
            if(flag1==true)
            break;
        }
        if(flag1==true)
        printf("Case #%d: NO\n",kase++);
        else
        printf("Case #%d: YES\n",kase++);
    }
    return 0;
}
