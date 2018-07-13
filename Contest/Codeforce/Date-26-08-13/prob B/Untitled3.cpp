#include <stdio.h>
int main()
{
    long long int n,m,i,time=0,pre,past;
    scanf("%I64d %I64d",&n,&m);
    past=1;
    for(i=0;i<m;i++)
    {
        scanf("%I64d",&pre);
        if(pre>past)
        time+=pre-past;
        else if(pre<past)
            //printf("%I64d %I64d %I64d\n",past,pre,m);
            time+=(n+pre-past);
        past=pre;
        //printf("%I64d\n",time);
    }
    printf("%I64d\n",time);
}
