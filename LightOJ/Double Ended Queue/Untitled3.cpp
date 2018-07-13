#include <stdio.h>
#include <deque>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    int t,kase=1,s,n,num,x,i;
    deque<int> d;
    string cmnd;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n",kase++);
        while(!d.empty())
        d.pop_back();
        cin>>s>>n;
        for(i=0;i<n;i++)
        {
            cin>>cmnd;
            if(cmnd=="pushLeft")
            {
                cin>>num;
                if(d.size()==s)
                {
                    puts("The queue is full");
                    continue;
                }
                d.push_front(num);
                printf("Pushed in left: %d\n",num);
            }
            else if(cmnd=="pushRight")
            {
                cin>>num;
                if(d.size()==s)
                {
                    puts("The queue is full");
                    continue;
                }
                d.push_back(num);
                printf("Pushed in right: %d\n",num);
            }
            else if(cmnd=="popLeft")
            {
                if(d.empty())
                {
                    puts("The queue is empty");
                    continue;
                }
                x=d.front();
                d.pop_front();
                printf("Popped from left: %d\n",x);
            }
            else if(cmnd=="popRight")
            {
                if(d.empty())
                {
                    puts("The queue is empty");
                    continue;
                }
                x=d.back();
                d.pop_back();
                printf("Popped from right: %d\n",x);
            }
        }
    }
}
