#include <stdio.h>
#include <map>
#include <iostream>
#include <string.h>
//map <char,int> m;
using namespace std;
int main()
{
    map <char,int> m;
    char c,chr[100000];
    int cost,ch,line,tcase,sum,i,l;
    double s;
    cin>>tcase;
    while(tcase--){
    m.clear();
    cin>>ch;
    while(ch--)
        {
          cin>>c>>cost;
          m[c]=cost;
        }
    cin>>line;
    getchar();
    sum=0;
    while(line--)
    {
        gets(chr);
        l=strlen(chr);
        for(i=0;i<l;i++)
        {
            if(m[chr[i]]!=0)
            {
                sum+=m[chr[i]];
            }
        }

    }
    s=1.0*sum/100;
    printf("%.2lf$\n",s);
    }
    return 0;
}




