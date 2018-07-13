#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#define pb push_back
#define pob pop_back
using namespace std;
int main()
{
    int t,kase=1;
    string url,cmnd;
    vector<string>frw,bk;
    scanf("%d",&t);
    while(t--){
    url="http://www.lightoj.com/";
    printf("Case %d:\n",kase++);
    frw.clear();
    bk.clear();
        for(;;)
        {
            cin>>cmnd;
            if(cmnd=="QUIT")
            break;
            else if(cmnd=="VISIT")
            {
                bk.pb(url);
                cin>>url;
                cout<<url<<endl;
                frw.clear();
            }
            else if(cmnd=="FORWARD")
            {
                if(frw.empty())
                {
                    puts("Ignored");
                    continue;
                }
                bk.pb(url);
                url=frw.back();
                frw.pob();
                cout<<url<<endl;
            }
            else if(cmnd=="BACK")
            {
                if(bk.empty())
                {
                    puts("Ignored");
                    continue;
                }
                frw.pb(url);
                url=bk.back();
                bk.pob();
                cout<<url<<endl;
            }

        }
    }
    return 0;
}
