#include <stdio.h>
#include <string.h>
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
  return i;
}
int main()
{
    char txt[250010],pat[250010];
    int t,l,ans,i,j;
        scanf("%d %s %s",&l,txt,pat);
        //l=strlen(txt);
        ans=kmp(txt,pat);
        if(ans==0)
        ans=-1;
        /*for(int i=ans,j=0;i<l;i++,j++)
        {
            if(txt[j]!=pat[i])
            {
                ans=-1;
                break;
            }
        }*/
        printf("%d\n",ans);
    return 0;
}
