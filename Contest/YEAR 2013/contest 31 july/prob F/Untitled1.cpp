#include <stdio.h>
#include <string.h>
int f[250010];
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
  while(j<n){
    if(i==m) return 2*m-j;
    if(text[j]==pattern[i]) {
      i++;
      j++;
    }
    else if(i>0)
    i=f[i];
    else j++;
  }
  return -1;
}
int main()
{
    char txt[500010],pat[250010],t[250010];
    int ans,l,i,j;
        scanf("%d %s %s",&l,t,pat);
        //l=strlen(txt);
        strcpy(txt,t);
        strcat(txt,t);
        ans=kmp(txt,pat);
        if(ans==0)
        ans=-1;
        if(ans==l)
        ans=0;
        printf("%d\n",ans);
    return 0;
}
