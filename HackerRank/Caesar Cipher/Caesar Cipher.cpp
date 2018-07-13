#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int n,k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;

    k=k%26;

    for(int i=0;i<n;i++)
    {
        char ch;

        if(s.at(i)>=65 && s.at(i)<=90)
        {
            ch=s.at(i)+k;

            if(ch>90)
            {
                ch=ch-26;
            }

            s[i]=ch;
        }
        else if(s.at(i)>=97 && s.at(i)<=122)
        {
            ch=s.at(i)+k;
            if(ch>122)
            {
                ch=ch-26;
            }
            else if(ch<97)
            {
               ch=s.at(i)-26+(k);
            }
            s[i]=ch;
        }
    }

    cout<<s;

    return 0;
}
