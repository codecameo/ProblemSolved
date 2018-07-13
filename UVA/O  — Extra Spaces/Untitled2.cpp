#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l,tcase,num,kase=1;
    char ch[60][600],ch1[60][600];
    cin>>tcase;
    while(tcase--)
    {
        memset(ch1,NULL,sizeof(ch1));
        memset(ch,NULL,sizeof(ch));
        cin>>num;
        getchar();
        k=-1;
        while(num--)
        {
            gets(ch[++k]);
            l=strlen(ch[k]);
            for(i=0,j=0;i<l;i++)
            {
                //if(!i)
                if(ch1[k][j-1]==' ' && ch[k][i]==' ')
                continue;
                ch1[k][j]=ch[k][i];
                j++;
            }
            //puts(ch1[k]);
        }
        cout<<"Case "<<kase++<<":"<<endl;
        for(i=0;i<=k;i++)
        {
              puts(ch1[i]);
        }
        if(tcase)
        cout<<endl;
    }
}
