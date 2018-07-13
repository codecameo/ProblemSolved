#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int i,kase=1;
    string a="HAJJ",b="UMRAH",st;
    for(;;)
    {
        getline(cin,st);
        if(st=="*")
        break;
        for (i=0;i<st.length();i++)
            {
                st[i]=toupper(st[i]);

            }
      printf("Case %d: ",kase++);
      if(st==a)
      cout<<"Hajj-e-Akbar"<<endl;
      else
      cout<<"Hajj-e-Asghar"<<endl;
    }

}
