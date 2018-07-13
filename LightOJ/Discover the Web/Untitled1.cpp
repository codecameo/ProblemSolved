#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>
using namespace std;
int main()
{
    int t,kase=1;
    string url,cmnd;
    stack<string>frw,back;
    scanf("%d",&t);
    while(t--){
    url="http://www.lightoj.com/";
    printf("Case %d:\n",kase++);
    while(!frw.empty())
        frw.pop();
    while(!back.empty())
        back.pop();
        for(;;)
        {
            cin>>cmnd;
            if(cmnd=="QUIT")
            break;
            else if(cmnd=="VISIT")
            {
                back.push(url);
                cin>>url;
                cout<<url<<endl;
                while(!frw.empty())
                frw.pop();
            }
            else if(cmnd=="FORWARD")
            {
                if(frw.empty())
                {
                    puts("Ignored");
                    continue;
                }
                back.push(url);
                url=frw.top();
                frw.pop();
                cout<<url<<endl;
            }
            else if(cmnd=="BACK")
            {
                if(back.empty())
                {
                    puts("Ignored");
                    continue;
                }
                frw.push(url);
                url=back.top();
                back.pop();
                cout<<url<<endl;
            }

        }
    }
    return 0;
}
