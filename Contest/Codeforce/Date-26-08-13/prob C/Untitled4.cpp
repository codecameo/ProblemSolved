#include <stdio.h>
#include <string.h>
int main()
{
    char st[12];
    int w1=-1,w2=-1,i,k,ans[10000],a,b,min,mn,count,ct,t,pre,j;
    bool w[12]={false},flag=false;
    gets(st);
    min=10000;
    for(i=0,count=0;i<10;i++)
    {
        if(st[i]=='1')
        {
            w[i+1]=true;
            count++;
            if(count==1){
            w1=i+1;
            //printf("%d\n",w1);
            }
            else if(count==2)
            {
                w2=i+1;
                //printf("%d\n",w2);
            }
        }
    }
    scanf("%d",&t);
    if(t==1)
    {
        for(i=1;i<=10;i++)
        {
            if(w[i])
            {
                puts("YES");
                printf("%d\n",i);
                return 0;
            }
        }
        puts("NO");
        return 0;
    }
    else if(t==2)
    {
        if(w1==-1 || w2==-1)
        puts("NO");
        else
        {
            puts("YES");
            printf("%d %d\n",w1,w2);
        }
        return 0;
    }
    //printf("%d %d\n",w1,w2);
    pre=w2;
    ans[0]=w1;
    ans[1]=w2;
    for(i=2,k=1;i<t;i++)
    {
       // printf("%d %d %d %d\n",k,w1,w2,pre);
        if(flag==1)
        {
            //puts("d");
            break;
        }
        if(i%2==0)
        {
            mn=w2-w1;
            //printf("1 %d\n",mn);
            for(j=mn+1;j<=10;j++)
            {
                if(w[j] && j!=pre)
                {
                    w1+=j;
                    break;
                }
            }
            if(j==11)
            flag=1;
        }
        else
        {
            mn=w1-w2;
            //printf("2 %d\n",mn);
            for(j=mn+1;j<=10;j++)
            {
                    if(w[j] && j!=pre)
                    {
                        w2+=j;
                        break;
                    }

            }
            if(j==11)
            flag=1;
        }
        pre=j;
        ans[++k]=pre;
    }
    if(flag==1)
    puts("NO");
    else
    {
        puts("YES");
        for(i=0;i<=k;i++)
        {
            if(i)
            printf(" ");
            printf("%d",ans[i]);
        }
        puts("");
        //printf("%d\n",k);
    }

    return 0;
}
