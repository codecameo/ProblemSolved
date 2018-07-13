#include <stdio.h>
#include <string.h>
long long int l,sum,num[1000010];
int pow(int b,int p){
if(!p) return 1;
return b*pow(b,p-1);
}
void bin(int k)
{
    int i,p,j;
    for(i=0,sum=0;i<=l-1;i++)
    {
        sum+=num[i]*pow(k,l-1-i);
    }
}
int main ()
{
    char ch[10000];
    int k,i,a,max;
    bool flag;
    gets(ch);
    l=strlen(ch);
    max=0;
    for(i=0;i<=l-1;i++)
    {
        if(ch[i]>48 && ch[i]<=57)
        num[i]=ch[i]-'0';
        else
        num[i]=ch[i]-55;
          if(max<num[i])
          a=max=num[i];
    }
    //printf("%d\n",a);
    for(k=a,flag=0;k<=36 && k>=2;k++)
    {
        bin(k);
        //printf("%d %lld\n",k,sum);
        if(sum%(k-1)==0)
        {
            flag=1;
            printf("%d\n",k);
            break;
        }
    }
    if(flag==0)
    printf("No solution.\n");
    return 0;
}
