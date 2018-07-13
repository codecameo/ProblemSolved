#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int f[1000010];
void F(char st[])
{
    int i,m,j;
    f[0]=f[1]=0;
    m=strlen(st);
    for(i=2;i<=m;i++)
    {
        j=f[i-1];
        for(;;)
        {
            if(st[i-1]==st[j])
            {
                f[i]=j+1;
                break;
            }
            if(j==0)
            {
                f[i]=0;
                break;
            }
            j=f[j];
        }
    }
}
int kmp(char text[],char pattern[])
{
  F(pattern);
  int i=0,j=0,count=0,n,m;
  n=strlen(text);
  m=strlen(pattern);
  for(;;){
    if(j==n) break;
    if(text[j]==pattern[i]) {
      i++;
      j++;
    }
    else if(i>0)
    i=f[i];
    else j++;
  }
  return n-i;
}
int main()
{
    char txt[1000010],pat[1000010];
    int kase=1,t,l,a;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        scanf("%s",txt);
        strcpy(pat,txt);
        l=strlen(pat);
        reverse(pat,pat+l);
        a=kmp(txt,pat);
        printf("Case %d: %d\n",kase++,a+l);
    }
    return 0;
}
