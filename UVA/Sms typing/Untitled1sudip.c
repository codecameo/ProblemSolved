#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main ()
{
    char ch[101],n[10];
    int k=0,j,l,i,p;
    //gets(n);
	//p=atoi(n);
	scanf("%d",&p);
    for(i=1;i<=p;i++)
    {
		k=0;
        gets(ch);
        l=strlen(ch);
        for(j=0;j<=l;j++)
        {
            if(ch[j]=='a' || ch[j]=='d' || ch[j]=='g' || ch[j]=='j' || ch[j]=='m' || ch[j]=='p' || ch[j]=='t' || ch[j]=='w'|| ch[j]==' ')
            k+=1;
            else if(ch[j]=='b' || ch[j]=='e' || ch[j]=='h' || ch[j]=='k' || ch[j]=='n' || ch[j]=='q' || ch[j]=='u' || ch[j]=='x')
            k+=2;
            else if(ch[j]=='c' || ch[j]=='f' || ch[j]=='i' || ch[j]=='l' || ch[j]=='o' || ch[j]=='r' || ch[j]=='v' || ch[j]=='y')
            k+=3;
            else if(ch[j]=='s' || ch[j]=='z')
            k+=4;

        }
            printf("Case #%d: %d\n",i,k);

     }
   return 0;
}
