#include <stdio.h>
#include <string.h>
int main ()
{
    int kase=1,i,l,a,e,s,r,g,f;
    char ch[30],eng[30],spa[30],ger[30],fre[30],ita[30],rus[30];
    strcpy(eng,"HELLO");
    strcpy(spa,"HOLA");
    strcpy(ger,"HALLO");
    strcpy(fre,"BONJOUR");
    strcpy(ita,"CIAO");
    strcpy(rus,"ZDRAVSTVUJTE");
    while(gets(ch)!=0)
    {
        a=strcmp(ch,"#");
        e=strcmp(ch,eng);
        s=strcmp(ch,spa);
        g=strcmp(ch,ger);
        f=strcmp(ch,fre);
        i=strcmp(ch,ita);
        r=strcmp(ch,rus);
        if(a==0)
        break;
        if(e==0)
        printf("Case %d: ENGLISH\n",kase);
        else if(g==0)
        printf("Case %d: GERMAN\n",kase);
        else if(s==0)
        printf("Case %d: SPANISH\n",kase);
        else if(i==0)
        printf("Case %d: ITALIAN\n",kase);
        else if(f==0)
        printf("Case %d: FRENCH\n",kase);
        else if(r==0)
        printf("Case %d: RUSSIAN\n",kase);
        else
        printf("Case %d: UNKNOWN\n",kase);
        kase++;
    }
    return 0;
}
