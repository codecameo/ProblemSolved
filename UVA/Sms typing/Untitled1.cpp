#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
    char ch[101],p[10];
    int n,k=0,j,l,i;
    //gets(p);
    //n=atoi(p);
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        gets(ch);
        l=strlen(ch);
        for(j=0;j<=l-1;j++)
        {
            if(ch[j]=='a' || ch[j]=='d' || ch[j]=='g' || ch[j]=='j' || ch[j]=='m' || ch[j]=='p' || ch[j]=='t' || ch[j]=='w')
            k+=1;
            else if(ch[j]=='b' || ch[j]=='e' || ch[j]=='h' || ch[j]=='k' || ch[j]=='n' || ch[j]=='q' || ch[j]=='u' || ch[j]=='x')
            k+=2;
            else if(ch[j]=='c' || ch[j]=='f' || ch[j]=='i' || ch[j]=='l' || ch[j]=='o' || ch[j]=='r' || ch[j]=='v' || ch[j]=='y')
            k+=3;
            else if(ch[j]=='s' || ch[j]=='z')
            k+=4;
            else
            k+=1;
        }   if(i>0)
            printf("Case #%d: %d\n",i,k);
            k=0;
     }
   return 0;
}
